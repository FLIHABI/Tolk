#ifndef OPCODE_MANAGER_HH
# define OPCODE_MANAGER_HH

# define MAX_OPCODE 256

class Environment;

namespace interpreter
{
  class OpcodeManager
  {
    public:
      OpcodeManager();

      typedef bool (*op_handler_type)(Environment& env);

      static bool handler_placeholder(Environment& env);
      void register_opcode_handler(unsigned char opcode,
                                   op_handler_type handler);
      bool handle(unsigned char opcode, Environment& env);

    private:
      op_handler_type handlers_[MAX_OPCODE];
  };
}

#endif /* end of include guard: OPCODE_MANAGER_HH */
