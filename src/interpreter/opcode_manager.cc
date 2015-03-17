#include <iostream>

#include "interpreter/opcode_manager.hh"

using namespace interpreter;

OpcodeManager::OpcodeManager()
{
  for (unsigned i = 0; i < MAX_OPCODE; ++i)
    handlers_[i] = handler_placeholder;
}

bool OpcodeManager::handler_placeholder(void)
{
  std::cerr << "Unknown opcode" << std::endl; //TODO: logging system
  return false;
}

void OpcodeManager::register_opcode_handler(unsigned char opcode,
                                            OpcodeManager::op_handler_type handler)
{
  handlers_[opcode] = handler;
}

bool OpcodeManager::handle(unsigned char opcode)
{
  return handlers_[opcode]();
}
