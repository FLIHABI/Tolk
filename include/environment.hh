#ifndef ENVIRONMENT_HH
# define ENVIRONMENT_HH

# include <vector>
# include <stdexcept>

# include "cpu/context.hh"
# include "cpu/base_cpu.hh"
# include "ressource/ressource.hh"

# define STACK_SIZE 4096
# define CTX_SIZE 4096

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
      if (cpu.regs.SP < 0)
        throw std::runtime_error("Stack underflow");

      return stack[cpu.regs.SP--];
    }

    inline void stack_push(int64_t value)
    {
      if (cpu.regs.SP >= STACK_SIZE - 1)
        throw std::runtime_error("Stack overflow");

      stack[++cpu.regs.SP] = value;
    }

    cpu::BaseCPU& cpu;
    std::vector<int64_t> stack;
    std::vector<cpu::Context> ctxs;
    ressource::RessourceManager& res;
};

#endif /* end of include guard: ENVIRONMENT_HH */
