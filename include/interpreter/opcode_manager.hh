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

      typedef void (*op_handler_type)(void); //FIXME

      void register_opcode_handler(unsigned char opcode, op_handler_type handler);

    private:
      static void handler_placeholder(void); //FIXME

      op_handler_type handlers[MAX_OPCODE];
  };
}

#endif /* end of include guard: OPCODE_MANAGER_HH */
