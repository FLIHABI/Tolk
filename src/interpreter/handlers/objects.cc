#include <cstdint>

#include "interpreter/handlers/handlers.hh"

bool create_handler(Environment& env)
{
  env.stack_push(env.res.add_object(env.stack_pop()));

  return true;
}

bool delete_handler(Environment& env)
{
  env.res.delete_object(env.stack_pop());

  return true;
}

bool read_handler(Environment& env)
{
  int64_t id = env.stack_pop();
  int64_t mem_id = env.stack_pop();

  env.stack_push(env.res.get_object(id)->at(mem_id));

  return true;
}

bool write_handler(Environment& env)
{
  int64_t id = env.stack_pop();
  int64_t mem_id = env.stack_pop();
  int64_t val = env.stack_pop();

  env.res.get_object(id)->at(mem_id) = val;

  return true;
}
