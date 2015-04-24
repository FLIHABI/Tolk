#include "cpu/cpu.hh"

using namespace cpu;

CPU::CPU(unsigned gen_reg,
         char* code,
         unsigned entry_point,
         interpreter::OpcodeManager op_manager)
  : BaseCPU(gen_reg, code, entry_point)
  , op_manager(op_manager)
{}
