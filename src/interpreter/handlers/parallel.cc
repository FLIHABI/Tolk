#include <cstdint>

#include "interpreter/handlers/handlers.hh"

bool interpreter::handlers::pcall_handler(Environment& env)
{
  int16_t fun_id = env.cpu.fetch_16bits_operand();
  std::vector<int64_t> params(env.res.get_function(fun_id).params.size());

  for (unsigned index = params.size(); index--; )
    params[index] = env.stack_pop();

  auto serialize = env.res.serialize_call(fun_id, params);
  std::string datas(reinterpret_cast<char*>(serialize.data()), serialize.size() * 8);
  env.stack_push(env.res.get_network_service().add_task(datas));
  return true;
}

bool interpreter::handlers::pwait_handler(Environment& env)
{
  int64_t task_id = env.stack_pop();

  //FIXME: slave returns string, deserialize is expecting vector ....
  //env.stack_push(env.res.deserialize_return(env.res.get_network_service().get_task_result(task_id).call_recv));
  return true;
}
