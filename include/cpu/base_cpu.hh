#ifndef BASE_CPU_HH
# define BASE_CPU_HH

# include <stack>
# include <cstdint>

# include "cpu/registers.hh"
# include "cpu/flags.hh"

namespace cpu
{
  class BaseCPU
  {
    public:
      BaseCPU(unsigned gen_reg,
              char* code,
              unsigned entry_point);
      virtual ~BaseCPU();

      virtual void run() = 0;

      inline unsigned char fetch()
      {
        return bytecode_[regs.PC++];
      }

      inline int16_t fetch_16bits_operand()
      {
        int16_t value = 0;

        for (int i = 0; i < 2; ++i)
          value |= (fetch() << (8 * i));

        return value;
      }

      inline int64_t fetch_64bits_operand()
      {
        int64_t value = 0;

        for (int i = 0; i < 8; ++i)
          value |= (fetch() << (8 * i));

        return value;
      }

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

      Registers regs;
      Flags flags;
      std::stack<int64_t> stack;

    protected:
      char* bytecode_;
  };
}

#endif /* end of include guard: BASE_CPU_HH */
