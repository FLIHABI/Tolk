#ifndef RESSOURCE_HH
# define RESSOURCE_HH

# include <unordered_map>
# include <list>
# include <stdexcept>
# include <string>
# include <thread>
# include <commons/tolkfile/tolk-file.hh>
# include <server.hh>

# include "task.hh"

namespace ressource
{
  class RessourceManager
  {
    public:
      RessourceManager();

      bool load_file(const std::string& filename);

      std::vector<uint64_t> serialize_call(uint16_t function_id,
                                           std::vector<int64_t>& stack);
      std::pair<unsigned, std::vector<uint64_t>> deserialize_call(std::vector<uint64_t>&);

      std::vector<uint64_t> serialize_return(uint16_t function_id,
                                             uint64_t return_value);

      uint64_t deserialize_return(std::vector<uint64_t>&);

      inline unsigned get_entry_point()
      {
        return tolk_file_->get_entry_point();
      }

      inline char* get_bytecode()
      {
        return const_cast<char*>(tolk_file_->get_bytecode().data());
      }

      inline std::string get_string(unsigned id)
      {
        return tolk_file_->get_strtable().get(id);
      }

      inline tolk::Function get_function(unsigned id)
      {
        return tolk_file_->get_functable().get(id);
      }

      inline unsigned add_object(unsigned member_count)
      {
        objects_[object_id_counter_] =
          std::make_unique<std::vector<int64_t>>(member_count);
        return object_id_counter_++;
      }

      inline void delete_object(unsigned id)
      {
        objects_[id].reset();
      }

      inline std::unique_ptr<std::vector<int64_t>>& get_object(unsigned id)
      {
        auto iter = objects_.find(id);

        if (iter == objects_.end())
          throw std::invalid_argument(
              "Unknown object id: " + std::to_string(id));

        if (!iter->second)
          throw std::invalid_argument(
              "Attempting to get a deleted object: " + std::to_string(id));

        return iter->second;
      }

      inline unsigned add_task(int16_t fun_id, std::vector<int64_t>& params)
      {
        tasks_.insert(
            std::make_pair( task_id_counter_,
                            task::Task(task_id_counter_, fun_id, params)));

        //task::Task& task = tasks_.at(task_id_counter_); //TODO: network
        auto network_datas = serialize_call(fun_id, params);
        server_->execBytecode(std::string(network_datas.begin(),
                                         network_datas.end()));
        return task_id_counter_++;
      }

      inline task::Task& get_task_result(unsigned id)
      {
        auto iter = tasks_.find(id);

        if (iter == tasks_.end())
          throw std::invalid_argument(
              "Unknown task id: " + std::to_string(id));

        while (!iter->second.is_complete)
          std::this_thread::yield();

        std::vector<uint64_t> result;
        std::string& res = server_->getResult(id)->value;
        result.assign(&res[0], &res[0] + res.size() / 4);
        iter->second.return_value = deserialize_return(result);
        return iter->second;
      }

    private:
      unsigned object_id_counter_;
      unsigned task_id_counter_;
      std::shared_ptr<tolk::TolkFile> tolk_file_;
      std::shared_ptr<Server> server_;
      std::unordered_map<unsigned, std::unique_ptr<std::vector<int64_t>>> objects_;
      std::unordered_map<unsigned, task::Task> tasks_;
  };
}

#endif /* end of include guard: RESSOURCE_HH */
