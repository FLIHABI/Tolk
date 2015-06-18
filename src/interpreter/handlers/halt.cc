#include <iostream>

#include "interpreter/handlers/handlers.hh"

bool interpreter::handlers::halt_handler(Environment& env)
{
  std::cout << "HALTED";

  if (env.cpu.regs.SP >= 0)
     std::cout << " (return value: " << env.stack_pop() << ")";

  std::cout << std::endl;

  return false;
}
