#ifndef HANDLERS_HH
# define HANDLERS_HH

# include "cpu/base_cpu.hh"

namespace interpreter
{
  namespace handlers
  {
    bool halt_handler(cpu::BaseCPU& cpu);
    bool push_handler(cpu::BaseCPU& cpu);
    bool pushr_handler(cpu::BaseCPU& cpu);
    bool pop_handler(cpu::BaseCPU& cpu);
    bool popr_handler(cpu::BaseCPU& cpu);
    bool add_handler(cpu::BaseCPU& cpu);
    bool sub_handler(cpu::BaseCPU& cpu);
    bool mul_handler(cpu::BaseCPU& cpu);
    bool div_handler(cpu::BaseCPU& cpu);
    bool mod_handler(cpu::BaseCPU& cpu);
  }
}

#endif /* end of include guard: HANDLERS_HH */
