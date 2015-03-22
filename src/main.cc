#include <iostream>

#include "cpu/cpu.hh"
#include "interpreter/opcode_manager.hh"

bool halt_handler(cpu::BaseCPU& cpu)
{
  std::cout << "Halting ..." << std::endl;
  return false;
}

bool print_pc_handler(cpu::BaseCPU& cpu)
{
  std::cout << "Current PC: " << cpu.regs.PC << std::endl;
  return true;
}

int main()
{
  interpreter::OpcodeManager opm;
  opm.register_opcode_handler('H', halt_handler);
  opm.register_opcode_handler('P', print_pc_handler);

  cpu::CPU cpu(1, (unsigned char*)"PPPH", 0, opm);
  cpu.run();
  return 0;
}
