#include "interpreter/handlers/handlers.hh"

bool interpreter::handlers::push_handler(Environment& env)
{
  env.stack_push(env.cpu.fetch_64bits_operand());

  return true;
}

bool interpreter::handlers::pushr_handler(Environment& env)
{
  env.stack_push(env.cpu.regs.greg[env.cpu.fetch_16bits_operand()]);

  return true;
}

bool interpreter::handlers::pop_handler(Environment& env)
{
  env.stack_pop();

  return true;
}

bool interpreter::handlers::popr_handler(Environment& env)
{
  env.cpu.regs.greg[env.cpu.fetch_16bits_operand()] = env.stack_pop();

  return true;
}
