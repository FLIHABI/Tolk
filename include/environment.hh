#ifndef ENVIRONMENT_HH
# define ENVIRONMENT_HH

# include <vector>
# include <stdexcept>

# include "cpu/context.hh"
# include "cpu/base_cpu.hh"
# include "ressource/ressource.hh"

namespace cpu
{
  class BaseCPU;
}

class Environment
{
  public:
    Environment(cpu::BaseCPU& cpu, ressource::RessourceManager& rm);

    void run();

    inline int64_t stack_pop()
    {
      if (cpu.regs.SP)
        return stack[cpu.regs.SP--];

      throw std::runtime_error("Poping an empty stack");
    }

    inline void stack_push(int64_t value)
    {
      stack.push_back(value);
      cpu.regs.SP++;
      //FIXME: stack overflow ?
    }

    cpu::BaseCPU& cpu;
    std::vector<int64_t> stack;
    std::vector<cpu::Context> ctxs;
    ressource::RessourceManager& res;
};

#endif /* end of include guard: ENVIRONMENT_HH */
