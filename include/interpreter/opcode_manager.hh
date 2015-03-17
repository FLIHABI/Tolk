#ifndef OPCODE_MANAGER_HH
# define OPCODE_MANAGER_HH

# define MAX_OPCODE 256

namespace interpreter
{
  class OpcodeManager
  {
    public:
      OpcodeManager();
      ~OpcodeManager();

      typedef bool (*op_handler_type)(void); //FIXME

      static bool handler_placeholder(void); //FIXME
      void register_opcode_handler(unsigned char opcode, op_handler_type handler);

    private:
      op_handler_type handlers_[MAX_OPCODE];
  };
}

#endif /* end of include guard: OPCODE_MANAGER_HH */
