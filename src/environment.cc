#include "environment.hh"

Environment::Environment(cpu::BaseCPU& cpu, ressource::RessourceManager& rm)
  : cpu(cpu)
  , stack(STACK_SIZE)
  , ctxs(CTX_SIZE)
  , res(rm)
{}

void Environment::run()
{
  while(cpu.op_manager.handle(cpu.fetch(), *this));
}
