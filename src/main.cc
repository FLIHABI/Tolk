#include <iostream>

#include "cpu/base_cpu.hh"
#include "loader.hh"
#include "environment.hh"
#include "ressource/ressource.hh"
#include "slave.hh"

int main(int argc, char* argv[])
{
  if (argc != 3)
  {
    std::cerr << "Usage: " << argv[0] << " <tolk file>"
              << "[-s|--server] | [-c|--client]"
              << std::endl;
    return 1;
  }

  interpreter::OpcodeManager opm;
  ressource::RessourceManager rm;

  Loader::get_instance().init_handlers_manager(opm);

  std::shared_ptr<Server> server;
  if (!rm.load_file(argv[1]))
  {
    std::cerr << "Cannot open file '" << argv[1] << "'" << std::endl;
    return 1;
  }

  //FIXME, ulgy and unsafe
  if (argv[2][1] == ('s') || argv[2][2] == ('s'))
      server = std::make_shared<Server>();

  rm.set_server(server);
  //TODO: read gen_reg from file

  if (server)
  {
      cpu::BaseCPU cpu(4096, rm.get_bytecode(), rm.get_entry_point(), opm);
      Environment env(cpu, rm);
      env.run();
  }
  else
  {
      //TODO clean ressource manager between each call
      while (1)
      {
          Slave s;
          std::string b = s.getBytecode();
          std::vector<uint64_t> result;
          result.assign(&b[0], &b[0] + b.size() / 4);
          auto p = rm.deserialize_call(result);
          //TODO call env
          cpu::BaseCPU cpu(4096, 
                           rm.get_bytecode(), 
                           rm.get_tolk_file()->get_functable().get(p.first).offset, 
                           opm);
          Environment env(cpu, rm);
          env.run();
          uint64_t ret = env.cpu.regs.greg[0];
          result = rm.serialize_return(p.first, ret);
          b = std::string(result.begin(), result.end());
          s.send_bytecode(b);
      }
  }


  return 0;
}
