#include <iostream>
#include <sstream>
#include <set>
#include <stdexcept>
#include <utility>
#include <list>

#include "ressource/ressource.hh"

using namespace std;

namespace ressource
{
  RessourceManager::RessourceManager(network::Service& svc)
    : object_id_counter_(0)
    , net_svc_(svc)
  {}

  bool RessourceManager::load_file(const string& filename)
  {
    return ((tolk_file_ = tolk::TolkFile::load(filename)) != nullptr);
  }

  bool RessourceManager::load_file(const std::vector<char>& datas)
  {
    istringstream iss(std::string(datas.data(), datas.size()));
    return ((tolk_file_ = tolk::TolkFile::load(iss)) != nullptr);
  }

  vector<char> RessourceManager::serialize_tolk_file()
  {
    ostringstream oss;

    if (!tolk_file_->save(oss))
      throw runtime_error("Cannot serialize tolk file");

    string content = oss.str();
    return vector<char>(content.begin(), content.end());
  }

  bool RessourceManager::is_struct_(unsigned kind)
  {
      return tolk_file_->get_structtable().get_table().find(kind)
             != tolk_file_->get_structtable().get_table().end();
  }

  void RessourceManager::serialize_struct_(unsigned elt,
                                           unsigned kind,
                                           vector<uint64_t>& result,
                                           list<std::pair<unsigned, unsigned>>& queue)
  {
      auto& ptr = get_object(elt);
      const tolk::Struct& s = tolk_file_->get_structtable().get_table().at(kind);
      for (unsigned i = 0; i < s.component.size(); i++)
      {
          result.push_back((*ptr)[i]);
          //FIXME: Know where objects definition start
          if (s.component[i] >= 2)
              queue.emplace_back((*ptr)[i], s.component[i]);
      }
  }


  void RessourceManager::serialize_array_(unsigned elt,
                                          unsigned kind,
                                          vector<uint64_t>& result,
                                          list<std::pair<unsigned, unsigned>>& queue)
  {
      auto& ptr = get_object(elt);
      const tolk::Symbol& s = tolk_file_->get_arraytable().get_table().at(kind);
      result.push_back(ptr->size());
      for (unsigned i = 0; i < ptr->size(); i++)
      {
          result.push_back((*ptr)[i]);
          //FIXME: Know where objects definition start
          if (s.offset >= 2)
              queue.emplace_back((*ptr)[i], s.offset);
      }
  }


  vector<uint64_t> RessourceManager::serialize_call(uint16_t function_id, vector<int64_t>& stack)
  {
    const tolk::Function& f = tolk_file_->get_functable().get_table().at(function_id);

    vector<uint64_t> result;
    set<unsigned> added;
    list<std::pair<unsigned, unsigned>> queue;

    //Add function id
    result.push_back(function_id);

    //Add function stack
    for (unsigned i = 0; i < stack.size(); i++)
    {
      result.push_back(stack[i]);
      //FIXME: Know where objects definition start, change magic number
      if (f.params[i] >= 2)
        queue.emplace_back(stack[i], f.params[i]);
    }

    //Add proper element
    while (queue.size() > 0)
    {

      unsigned elt = queue.front().first;
      unsigned kind = queue.front().second;
      queue.pop_front();

      if (added.count(elt) > 0)
        continue;


      added.insert(elt);

      result.push_back(elt);
      result.push_back(kind);

      if (is_struct_(kind))
        serialize_struct_(elt, kind, result, queue);
      else
        serialize_array_(elt, kind, result, queue);

    }
    //TODO: serialize used register
    return result;
  }

  pair<unsigned, vector<uint64_t>>
    RessourceManager::deserialize_call(vector<uint64_t>& array)
    {
      list<int64_t> list {array.begin(), array.end()};
      uint16_t function_id = list.front();
      list.pop_front();

      std::vector<uint64_t> stack;

      const tolk::Function& f = tolk_file_->get_functable().get_table().at(function_id);
      for (unsigned i = 0; i < f.params.size(); i++)
      {
        stack.push_back(list.front());
        list.pop_front();
      }

      while (list.size() > 0)
      {
        unsigned id = list.front();
        list.pop_front();
        unsigned kind = list.front();
        list.pop_front();

        unsigned size = 0;
        if (is_struct_(kind))
            size = tolk_file_->get_structtable().get_table().at(kind).component.size();
        else // We are on an array
        {
            size = list.front();
            list.pop_front();
        }

        objects_[id] = make_unique<vector<int64_t>>(size);

        for (unsigned i = 0; i < size; i++)
        {
          (*objects_[id])[i] = list.front();
          if (object_id_counter_ <= id)
              object_id_counter_ = id + 1;
          list.pop_front();
        }
      }

      return std::make_pair(function_id, std::move(stack));
    }

  vector<uint64_t>
  RessourceManager::serialize_return(uint16_t function_id, uint64_t return_value)
  {
      const tolk::Function& f = tolk_file_->get_functable().get_table().at(function_id);

      vector<uint64_t> result;
      result.push_back(return_value);
      result.push_back(f.return_value);
      if (f.return_value < 2)
          return result;

      set<unsigned> added;
      list<std::pair<unsigned, unsigned>> queue;
      queue.emplace_back(return_value, f.return_value);

      while (queue.size() > 0)
      {
          unsigned elt = queue.front().first;
          unsigned kind = queue.front().second;
          queue.pop_front();

          if (added.count(elt) > 0)
              continue;


          added.insert(elt);

          result.push_back(elt);
          result.push_back(kind);

          if (is_struct_(kind))
              serialize_struct_(elt, kind, result, queue);
          else
              serialize_array_(elt, kind, result, queue);
      }

      return result;
  }

  uint64_t
  RessourceManager::deserialize_return(vector<uint64_t>& array)
  {
      list<int64_t> list {array.begin(), array.end()};
      int64_t value = list.front();
      list.pop_front();
      int64_t kind = list.front();
      list.pop_front();
      if (kind < 2)
          return value;

      map<unsigned, unsigned> equivalence;
      std::list<std::pair<unsigned, unsigned>> new_objs;
      while (list.size() > 0)
      {
          unsigned id = list.front();
          list.pop_front();
          unsigned kind = list.front();
          list.pop_front();

          unsigned size = 0;
          if (is_struct_(kind))
              size = tolk_file_->get_structtable().get_table().at(kind).component.size();
          else // We are on an array
          {
              size = list.front();
              list.pop_front();
          }

          unsigned new_id = add_object(size);

          new_objs.emplace_back(new_id, kind);
          equivalence[id] = new_id;

          for (unsigned i = 0; i < size; i++)
          {
              (*objects_[new_id])[i] = list.front();
              list.pop_front();
          }
      }

      while (new_objs.size() > 0)
      {
          unsigned id = new_objs.front().first;
          unsigned kind = new_objs.front().second;
          new_objs.pop_front();

          if (is_struct_(kind))
          {
              const tolk::Struct& s = tolk_file_->get_structtable().get_table().at(kind);
              for (unsigned i = 0; i < objects_[i]->size(); i++)
              {
                  if (s.component[i] >= 2)
                      (*objects_[id])[i] = equivalence[(*objects_[id])[i]];
              }
          }
          else //Array
          {
              unsigned is_obj = tolk_file_->get_arraytable().get_table().at(kind).offset;
              if (is_obj >= 2)
                  for (unsigned i = 0; i < objects_[i]->size(); i++)
                      (*objects_[id])[i] = equivalence[(*objects_[id])[i]];
          }
      }

      return value;
  }
}

#if 0
Send a call: need to know the function id and parameters
| FUNCTION ID | PARAMS STACK | ENV
| OBJECT ID
| OBJECT KIND
| COMPONENT
\-> get all this parameters
serialize them
get all register involved
serialize them
Receive a call
\-> build the environment
Receive a value
| RETURN VALUE | ENV
//SOMETHING CLEVER
#endif
