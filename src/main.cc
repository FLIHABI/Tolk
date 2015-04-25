#include <iostream>
#include <fstream>

#include "cpu/base_cpu.hh"
#include "loader.hh"
#include "environment.hh"
#include "ressource/ressource.hh"

static char* read_input_file(char* filename)
{
  std::ifstream is(filename);

  if (!is)
  {
    std::cerr << "Cannot open file '" << filename << "'" << std::endl;
    std::exit(1);
  }

  is.seekg(0, is.end);
  int size = is.tellg();
  is.seekg(0, is.beg);

  char* bytecode = new char[size];

  if (!is.read(bytecode, size))
  {
    std::cerr << "Cannot read file" << std::endl;
    is.close();
    std::exit(1);
  }

  is.close();

  return bytecode;
}

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    std::cerr << "Usage: " << argv[0] << " <input>" << std::endl;
    return 1;
  }

  interpreter::OpcodeManager opm;
  ressource::RessourceManager rm;
  Loader::get_instance().init_handlers_manager(opm);
  Loader::get_instance().load_ressources(rm);

  char* bytecode = read_input_file(argv[1]); //TODO: file loader
  unsigned gen_reg = 1; //TODO: read gen_reg from file

  cpu::BaseCPU cpu(gen_reg, bytecode, 0, opm);
  Environment env(cpu, rm);

  env.run();

  delete[] bytecode;

  return 0;
}
