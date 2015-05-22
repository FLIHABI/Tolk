#ifndef RESSOURCE_HH
# define RESSOURCE_HH

# include <unordered_map>
# include <stdexcept>
# include <string>
# include <commons/tolkfile/tolk-file.hh>

namespace ressource
{
  class RessourceManager
  {
    public:
      ~RessourceManager();

      void load_file(const std::string& filename);

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
        objects_[object_id_counter_] = new std::vector<int64_t>(member_count);
        return object_id_counter_++;
      }

      inline void delete_object(unsigned id)
      {
        delete objects_[id];
      }

      inline std::vector<int64_t>* get_object(unsigned id)
      {
        auto iter = objects_.find(id);

        if (iter == objects_.end())
          throw std::invalid_argument("Unknown object id: " + std::to_string(id));

        return iter->second;
      }

    private:
      unsigned object_id_counter_;
      std::shared_ptr<tolk::TolkFile> tolk_file_;
      std::unordered_map<unsigned, std::vector<int64_t>*> objects_;
  };
}

#endif /* end of include guard: RESSOURCE_HH */
