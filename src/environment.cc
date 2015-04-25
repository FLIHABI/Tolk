#include "environment.hh"

Environment::Environment(cpu::BaseCPU& cpu, ressource::RessourceManager& rm)
  : cpu(cpu)
  , res(rm)
{}

void Environment::run()
{
  while(cpu.op_manager.handle(cpu.fetch(), *this));
}
