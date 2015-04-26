#ifndef RESSOURCE_HH
# define RESSOURCE_HH

# include <unordered_map>
# include <stdexcept>
# include <string>

namespace ressource
{
  class RessourceManager
  {
    public:
      inline std::string get_string(unsigned id)
      {
        auto iter = strings_.find(id);

        if (iter == strings_.end())
          throw std::invalid_argument("Unknown string id: " + std::to_string(id));

        return iter->second;
      }

      inline void add_string(unsigned id, std::string value)
      {
        strings_[id] = value;
      }

      inline void add_object(unsigned id, char* ptr)
      {
        objects_[id] = ptr;;
      }

      inline void add_symbol(unsigned id, unsigned addr)
      {
        symbols_[id] = addr;
      }

      inline char* get_object(unsigned id)
      {
        auto iter = objects_.find(id);

        if (iter == objects_.end())
          throw std::invalid_argument("Unknown object id: " + std::to_string(id));

        return iter->second;
      }

      inline unsigned get_symbol(unsigned id)
      {
        auto iter = symbols_.find(id);

        if (iter == symbols_.end())
          throw std::invalid_argument("Unknown symbol id: " + std::to_string(id));

        return iter->second;
      }

    private:
      std::unordered_map<unsigned, std::string> strings_;
      std::unordered_map<unsigned, char*> objects_;
      std::unordered_map<unsigned, unsigned> symbols_;
  };
}

#endif /* end of include guard: RESSOURCE_HH */
