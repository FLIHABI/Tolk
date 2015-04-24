#include <iostream>

#include "interpreter/opcode_manager.hh"

using namespace interpreter;

OpcodeManager::OpcodeManager()
{
  for (unsigned i = 0; i < MAX_OPCODE; ++i)
    handlers_[i] = handler_placeholder;
}

bool OpcodeManager::handler_placeholder(Environment& env)
{
  std::cerr << "Unknown opcode" << std::endl; //TODO: logging system
  return false;
}

void OpcodeManager::register_opcode_handler(unsigned char opcode,
                                            op_handler_type handler)
{
  handlers_[opcode] = handler;
}

bool OpcodeManager::handle(unsigned char opcode, Environment& env)
{
  return handlers_[opcode](env);
}
