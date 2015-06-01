#include <iostream>

#include "cpu/base_cpu.hh"
#include "loader.hh"
#include "environment.hh"
#include "ressource/ressource.hh"

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    std::cerr << "Usage: " << argv[0] << " <tolk file>" << std::endl;
    return 1;
  }

  interpreter::OpcodeManager opm;
  ressource::RessourceManager rm;

  Loader::get_instance().init_handlers_manager(opm);

  if (!rm.load_file(argv[1]))
  {
    std::cerr << "Cannot open file '" << argv[1] << "'" << std::endl;
    return 1;
  }

  //TODO: read gen_reg from file
  cpu::BaseCPU cpu(4096, rm.get_bytecode(), rm.get_entry_point(), opm);
  Environment env(cpu, rm);

  env.run();

  return 0;
}
