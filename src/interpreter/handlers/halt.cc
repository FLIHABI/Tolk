#include "interpreter/handlers/halt.hh"

using namespace interpreter::handlers;

bool halt_handler(__attribute__((unused)) cpu::BaseCPU& cpu)
{
  return false;
}
