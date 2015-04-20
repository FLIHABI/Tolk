#ifndef CPU_HH
# define CPU_HH

# include "cpu/base_cpu.hh"
# include "interpreter/opcode_manager.hh"

namespace cpu
{
  class CPU : public BaseCPU
  {
    public:
      CPU(unsigned gen_reg,
          char* code,
          unsigned entry_point,
          interpreter::OpcodeManager op_manager);

      void run();

    private:
      interpreter::OpcodeManager op_manager_;
  };
}

#endif /* end of include guard: CPU_HH */
