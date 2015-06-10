#include <cstdint>

#include "interpreter/handlers/handlers.hh"

bool interpreter::handlers::pcall_handler(Environment& env)
{
  int16_t fun_id = env.cpu.fetch_16bits_operand();
  std::vector<int64_t> params(env.res.get_function(fun_id).params.size());

  for (unsigned index = params.size(); index--; )
    params[index] = env.stack_pop();

  int64_t task_id = 0; //FIXME

  env.stack_push(task_id);

  return true;
}

bool interpreter::handlers::pwait_handler(Environment& env)
{
  int64_t task_id = env.stack_pop();

  return true;
}
