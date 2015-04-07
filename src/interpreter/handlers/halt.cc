#include "interpreter/handlers/halt.hh"

bool interpreter::handlers::halt_handler(__attribute__((unused)) cpu::BaseCPU& cpu)
{
  return false;
}
