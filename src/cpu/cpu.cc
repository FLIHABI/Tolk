#include "cpu/cpu.hh"

using namespace cpu;

CPU::CPU(unsigned gen_reg,
         unsigned char* code,
         unsigned entry_point,
         interpreter::OpcodeManager op_manager)
  : BaseCPU(gen_reg, code, entry_point)
  , op_manager_(op_manager)
{}

void CPU::run()
{
  while(op_manager_.handle(fetch(), *this));
}
