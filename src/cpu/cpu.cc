#include "cpu/cpu.hh"

using namespace cpu;

CPU::CPU(unsigned gen_reg,
         unsigned char* code,
         unsigned entry_point,
         interpreter::OpcodeManager op_manager)
  : regs(gen_reg)
  , bytecode_(code)
  , op_manager_(op_manager)
{
  regs.PC = entry_point;
}

inline unsigned char CPU::fetch_opcode()
{
  return bytecode_[regs.PC++];
}

void CPU::run()
{
  while(op_manager_.handle(fetch_opcode()));
}
