#include <cstdint>

#include "interpreter/handlers/handlers.hh"

bool interpreter::handlers::pcall_handler(Environment& env)
{
  int16_t fun_id = env.cpu.fetch_16bits_operand();

  int64_t task_id = 0; //FIXME

  env.stack_push(task_id);

  return true;
}

bool interpreter::handlers::pwait_handler(Environment& env)
{
  int64_t task_id = env.stack_pop();

  return true;
}
