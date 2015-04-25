#include <commons/asm/bytecodes.hh>
#include "loader.hh"
#include "interpreter/handlers/handlers.hh"

using namespace interpreter::handlers;
using namespace ressource;

Loader::Loader()
{}

Loader& Loader::get_instance()
{
  static Loader instance;

  return instance;
}

void Loader::init_handlers_manager(interpreter::OpcodeManager& opm)
{
  opm.register_opcode_handler(OP_HALT, halt_handler);
  opm.register_opcode_handler(OP_PUSH, push_handler);
  opm.register_opcode_handler(OP_PUSHR, pushr_handler);
  opm.register_opcode_handler(OP_POP, pop_handler);
  opm.register_opcode_handler(OP_POPR, popr_handler);
  opm.register_opcode_handler(OP_ADD, add_handler);
  opm.register_opcode_handler(OP_SUB, sub_handler);
  opm.register_opcode_handler(OP_MUL, mul_handler);
  opm.register_opcode_handler(OP_DIV, div_handler);
  opm.register_opcode_handler(OP_MOD, mod_handler);
}

void Loader::load_ressources(RessourceManager& rm)
{
  //TODO: load ressources from file
}
