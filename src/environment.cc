#include "environment.hh"

Environment::Environment(cpu::BaseCPU& cpu)
  : cpu(cpu)
{}

void Environment::run()
{
  while(cpu.op_manager.handle(cpu.fetch(), *this));
}
