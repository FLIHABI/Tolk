#include <iostream>

#include "interpreter/handlers/handlers.hh"

bool interpreter::handlers::halt_handler(Environment& env)
{
  std::cout << "HALTED";

  if (env.stack.size())
     std::cout << " (return value: " << env.stack_pop() << ")";

  std::cout << std::endl;

  return false;
}
