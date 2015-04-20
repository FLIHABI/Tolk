#ifndef HANDLERS_HH
# define HANDLERS_HH

# include "cpu/base_cpu.hh"

namespace interpreter
{
  namespace handlers
  {
    bool halt_handler(cpu::BaseCPU& cpu);
  }
}

#endif /* end of include guard: HANDLERS_HH */
