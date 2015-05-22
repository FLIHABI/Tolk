#include <cstdint>

#include "interpreter/handlers/handlers.hh"

bool interpreter::handlers::save_handler(Environment& env)
{
  int16_t id = env.cpu.fetch_16bits_operand();
  tolk::Function func = env.res.get_function(id);

  for (unsigned i = 0; i < func.registers; ++i) {
    env.stack_push(env.cpu.regs.greg[func.registers_offset + i]);
  }

  return true;
}

bool interpreter::handlers::restore_handler(Environment& env)
{
  int16_t id = env.cpu.fetch_16bits_operand();
  tolk::Function func = env.res.get_function(id);

  for (unsigned i = func.registers; i > 0; --i) {
    auto aux = env.stack_pop();
    env.cpu.regs.greg[func.registers_offset + i - 1] = aux;
  }

  return true;
}

bool interpreter::handlers::setr_handler(Environment& env)
{
  int16_t reg = env.cpu.fetch_16bits_operand();
  int64_t val = env.cpu.fetch_64bits_operand();

  env.cpu.regs.greg[reg] = val;

  return true;
}
