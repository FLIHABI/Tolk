#ifndef LOADER_HH
# define LOADER_HH

# include "interpreter/opcode_manager.hh"
# include "ressource/ressource.hh"

class Loader
{
  public:
    static Loader& get_instance();

    void init_handlers_manager(interpreter::OpcodeManager& opm);
    void load_file( const std::string& filename,
                          ressource::RessourceManager& rm);

  private:
    Loader();
};

#endif /* end of include guard: LOADER_HH */
