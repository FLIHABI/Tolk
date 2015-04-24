#include <cstdint>

#include "interpreter/handlers/handlers.hh"

bool interpreter::handlers::add_handler(Environment& env)
{
  int64_t value2 = env.stack_pop();
  int64_t value1 = env.stack_pop();

  env.stack_push(value1 + value2);

  return true;
}

bool interpreter::handlers::sub_handler(Environment& env)
{
  int64_t value2 = env.stack_pop();
  int64_t value1 = env.stack_pop();

  env.stack_push(value1 - value2);

  return true;
}

bool interpreter::handlers::mul_handler(Environment& env)
{
  int64_t value2 = env.stack_pop();
  int64_t value1 = env.stack_pop();

  env.stack_push(value1 * value2);

  return true;
}

bool interpreter::handlers::div_handler(Environment& env)
{
  int64_t value2 = env.stack_pop();
  int64_t value1 = env.stack_pop();

  env.stack_push(value1 / value2);

  return true;
}

bool interpreter::handlers::mod_handler(Environment& env)
{
  int64_t value2 = env.stack_pop();
  int64_t value1 = env.stack_pop();

  env.stack_push(value1 % value2);

  return true;
}
