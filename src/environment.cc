#include "environment.hh"
#include "random.hh"
#include "print.hh"

Environment::Environment(cpu::BaseCPU& cpu, ressource::RessourceManager& rm)
  : cpu(cpu)
  , stack(STACK_SIZE)
  , ctx_stack(CTX_STACK_SIZE)
  , ctxs(CTX_SIZE)
  , res(rm)
{

    funs["get_random"] = get_random;
    funs["init_random"] = init_random;

    funs["print_int"] = print_int;
    funs["print_newline"] = print_newline;
    funs["print_string"] = print_string;
}

void Environment::run()
{
  while(cpu.op_manager.handle(cpu.fetch(), *this));
}
