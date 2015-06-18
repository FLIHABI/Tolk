#ifndef RESSOURCE_HH
# define RESSOURCE_HH

# include <unordered_map>
# include <list>
# include <stdexcept>
# include <string>
# include <thread>

# include "commons/tolkfile/tolk-file.hh"
# include "service.hh"

namespace ressource
{
  class RessourceManager
  {
    public:
      using object_type = std::unique_ptr<std::vector<int64_t>>;

      RessourceManager(network::Service& svc);

      bool load_file(const std::string& filename);
      bool load_file(const std::vector<char>& datas);
      std::vector<uint64_t> serialize_call(uint16_t, std::vector<int64_t>&);
      std::pair<unsigned, std::vector<uint64_t>>
        deserialize_call(std::vector<uint64_t>&);
      std::vector<uint64_t> serialize_return(uint16_t, uint64_t);
      uint64_t deserialize_return(std::vector<uint64_t>&);
      std::vector<char> serialize_tolk_file();

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

      inline object_type& get_object(unsigned id)
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

      inline std::shared_ptr<tolk::TolkFile> get_tolk_file()
      {
        return tolk_file_;
      }

      inline network::Service& get_network_service()
      {
        return net_svc_;
      }

    private:
      void serialize_struct_(unsigned elt,
          unsigned kind,
          std::vector<uint64_t>& result,
          std::list<std::pair<unsigned, unsigned>>& queue);

      void serialize_array_(unsigned elt,
          unsigned kind,
          std::vector<uint64_t>& result,
          std::list<std::pair<unsigned, unsigned>>& queue);

      bool is_struct_(unsigned kind);

      unsigned object_id_counter_;
      std::shared_ptr<tolk::TolkFile> tolk_file_;
      std::unordered_map<unsigned, object_type> objects_;
      network::Service& net_svc_;
  };
}

#endif /* end of include guard: RESSOURCE_HH */
