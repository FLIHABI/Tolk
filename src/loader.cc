#include <commons/asm/bytecodes.hh>
#include "loader.hh"
#include "interpreter/handlers/handlers.hh"

using namespace interpreter::handlers;

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
  //TODO: add other handlers
}
