#ifndef CPU_HH
# define CPU_HH

# include <stack>

# include "cpu/registers.hh"
# include "cpu/flags.hh"
# include "interpreter/opcode_manager.hh"

namespace cpu
{
  class CPU
  {
    public:
      CPU(unsigned gen_reg,
          unsigned char* code,
          unsigned entry_point,
          interpreter::OpcodeManager op_manager);

      void run();
      inline unsigned char fetch_opcode();

      Registers regs;
      Flags flags;

    private:
      std::stack<long long> stack_;
      unsigned char* bytecode_;
      interpreter::OpcodeManager op_manager_;
  };
}

#endif /* end of include guard: CPU_HH */
