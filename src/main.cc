#include "cpu/cpu.hh"
#include "loader.hh"

int main()
{
  interpreter::OpcodeManager opm;
  Loader::get_instance().init_handlers_manager(opm);

  cpu::CPU cpu(1, (unsigned char*)"", 0, opm);
  cpu.run();

  return 0;
}
