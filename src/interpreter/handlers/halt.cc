#include <iostream>

#include "interpreter/handlers/handlers.hh"

bool interpreter::handlers::halt_handler(cpu::BaseCPU& cpu)
{
  std::cout << "HALTED";

  if (cpu.stack.size())
     std::cout << " (return value: " << cpu.stack_pop() << ")";

  std::cout << std::endl;

  return false;
}
