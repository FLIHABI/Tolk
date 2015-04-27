#include <cstdint>

#include "interpreter/handlers/handlers.hh"

bool interpreter::handlers::add_handler(Environment& env)
{
  int64_t value2 = env.stack_pop();
  env.stack[env.cpu.regs.SP] += value2;

  return true;
}

bool interpreter::handlers::sub_handler(Environment& env)
{
  int64_t value2 = env.stack_pop();
  env.stack[env.cpu.regs.SP] -= value2;

  return true;
}

bool interpreter::handlers::mul_handler(Environment& env)
{
  int64_t value2 = env.stack_pop();
  env.stack[env.cpu.regs.SP] *= value2;

  return true;
}

bool interpreter::handlers::div_handler(Environment& env)
{
  int64_t value2 = env.stack_pop();
  env.stack[env.cpu.regs.SP] /= value2;

  return true;
}

bool interpreter::handlers::mod_handler(Environment& env)
{
  int64_t value2 = env.stack_pop();
  env.stack[env.cpu.regs.SP] %= value2;

  return true;
}
