#include <cstdint>

#include "interpreter/handlers/handlers.hh"

static void call_function(int64_t id, Environment& env)
{
  env.save_ctx();

  env.cpu.regs.PC = env.res.get_function(id).offset;
}

bool interpreter::handlers::call_handler(Environment& env)
{
  call_function(env.cpu.fetch_16bits_operand(), env);

  return true;
}

bool interpreter::handlers::callr_handler(Environment& env)
{
  call_function(env.cpu.regs.greg[env.cpu.fetch_16bits_operand()], env);

  return true;
}

bool interpreter::handlers::ret_handler(Environment& env)
{
  switch (env.res.get_network_service().get_mode())
  {
    case network::SERVER:
      env.restore_ctx();
      return true;

    case network::CLIENT:
      if (env.cpu.regs.CSP >= 0)
      {
        env.restore_ctx();
        return true;
      }

    default:
      return false;
  }
}
