#ifndef ENVIRONMENT_HH
# define ENVIRONMENT_HH

# include <vector>
# include <map>
# include <stdexcept>

# include "cpu/context.hh"
# include "cpu/base_cpu.hh"
# include "ressource/ressource.hh"

# define STACK_SIZE 4096
# define CTX_STACK_SIZE 4096
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

    inline int64_t ctx_stack_pop()
    {
      if (cpu.regs.CSP < 0)
        throw std::runtime_error("Context Stack underflow");

      return ctx_stack[cpu.regs.CSP--];
    }

    inline void ctx_stack_push(int64_t value)
    {
      if (cpu.regs.CSP >= STACK_SIZE - 1)
        throw std::runtime_error("Context Stack overflow");

      ctx_stack[++cpu.regs.CSP] = value;
    }

    inline void save_ctx()
    {
      if (cpu.regs.CP >= CTX_SIZE - 1)
        throw std::runtime_error("Context overflow");

      cpu.regs.CP++;
      ctxs[cpu.regs.CP].IP = cpu.regs.PC;
    }

    inline void restore_ctx()
    {
      if (cpu.regs.CP < 0)
        throw std::runtime_error("Context underflow");

      cpu.regs.PC = ctxs[cpu.regs.CP].IP;
      cpu.regs.CP--;
    }

    cpu::BaseCPU& cpu;
    std::vector<int64_t> stack;
    std::vector<int64_t> ctx_stack;
    std::vector<cpu::Context> ctxs;
    //Sorry
    std::map<std::string, std::function<void(Environment&)>> funs;
    ressource::RessourceManager& res;
};

#endif /* end of include guard: ENVIRONMENT_HH */
