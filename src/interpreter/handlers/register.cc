#include <cstdint>

#include "interpreter/handlers/handlers.hh"

bool save_handler(Environment& env)
{
  int16_t id = env.cpu.fetch_16bits_operand();
  tolk::Function func = env.res.get_function(id);

  for (unsigned i = 0; i < func.registers; ++i)
    env.stack_push(env.cpu.regs.greg[func.registers_offset + i]);

  return true;
}

bool restore_handler(Environment& env)
{
  int16_t id = env.cpu.fetch_16bits_operand();
  tolk::Function func = env.res.get_function(id);

  for (unsigned i = func.registers; func.registers; --i)
    env.cpu.regs.greg[func.registers_offset + i - 1] = env.stack_pop();

  return true;
}

bool setr_handler(Environment& env)
{
  int16_t reg = env.cpu.fetch_16bits_operand();
  int64_t val = env.cpu.fetch_64bits_operand();

  env.cpu.regs.greg[reg] = val;

  return true;
}
