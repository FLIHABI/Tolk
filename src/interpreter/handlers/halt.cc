#include <iostream>

#include "interpreter/handlers/handlers.hh"

bool interpreter::handlers::halt_handler(cpu::BaseCPU& cpu)
{
  std::cout << "HALTED (return value: " << cpu.stack_pop() << " )" << std::endl;
  return false;
}
