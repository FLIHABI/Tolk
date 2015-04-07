#ifndef HALT_HH
# define HALT_HH

# include "cpu/base_cpu.hh"

namespace interpreter
{
  namespace handlers
  {
    bool halt_handler(cpu::BaseCPU& cpu);
  }
}

#endif /* end of include guard: HALT_HH */
