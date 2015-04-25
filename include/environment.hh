#ifndef ENVIRONMENT_HH
# define ENVIRONMENT_HH

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
      int64_t top = stack.top();
      stack.pop();

      return top;
    }

    inline void stack_push(int64_t value)
    {
      stack.push(value);
    }

    cpu::BaseCPU& cpu;
    std::stack<int64_t> stack;
    ressource::RessourceManager& res;
};

#endif /* end of include guard: ENVIRONMENT_HH */
