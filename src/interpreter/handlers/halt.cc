#include "interpreter/handlers/handlers.hh"

bool interpreter::handlers::halt_handler(__attribute__((unused)) cpu::BaseCPU& cpu)
{
  return false;
}
