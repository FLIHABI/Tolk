#ifndef LOADER_HH
# define LOADER_HH

# include "interpreter/opcode_manager.hh"

class Loader
{
  public:
    static Loader& get_instance();

    void init_handlers_manager(interpreter::OpcodeManager& opm);
    void load_ressources(ressource::RessourceManager& rm);

  private:
    Loader();
};

#endif /* end of include guard: LOADER_HH */
