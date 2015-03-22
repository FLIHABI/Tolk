#ifndef OPCODE_MANAGER_HH
# define OPCODE_MANAGER_HH

# include "cpu/base_cpu.hh"

# define MAX_OPCODE 256

namespace interpreter
{
  class OpcodeManager
  {
    public:
      OpcodeManager();

      typedef bool (*op_handler_type)(cpu::BaseCPU& cpu);

      static bool handler_placeholder(cpu::BaseCPU& cpu);
      void register_opcode_handler(unsigned char opcode,
                                   op_handler_type handler);
      bool handle(unsigned char opcode, cpu::BaseCPU& cpu);

    private:
      op_handler_type handlers_[MAX_OPCODE];
  };
}

#endif /* end of include guard: OPCODE_MANAGER_HH */
