#include <iostream>

#include "interpreter/opcode_manager.hh"

OpcodeManager::OpcodeManager()
{
  for (unsigned i = 0; i < MAX_OPCODE; ++i)
    handlers[i] = handler_placeholder;
}

void OpcodeManager::handler_placeholder(void)
{
  std::cerr << "Unknown opcode" << std::endl;
}

void OpcodeManager::register_opcode_handler(unsigned char opcode,
                                            OpcodeManager::op_handler_type handler)
{
  handlers[opcode] = handler;
}
