#include "cpu/base_cpu.hh"

using namespace cpu;

BaseCPU::BaseCPU(unsigned gen_reg, unsigned char* code, unsigned entry_point)
  : regs(gen_reg)
  , flags()
  , bytecode_(code)
{
  regs.PC = entry_point;
}

BaseCPU::~BaseCPU()
{}
