#include <cstdint>

#include "interpreter/handlers/handlers.hh"

bool interpreter::handlers::save_handler(Environment& env)
{
  int16_t id = env.cpu.fetch_16bits_operand();
  tolk::Function func = env.res.get_function(id);

  for (unsigned i = 0; i < func.registers; ++i)
    env.stack_push(env.cpu.regs.greg[func.registers_offset + i]);

  std::cout << "----" << std::endl;
  return true;
}

bool interpreter::handlers::restore_handler(Environment& env)
{
  int16_t id = env.cpu.fetch_16bits_operand();
  tolk::Function func = env.res.get_function(id);

  for (unsigned i = func.registers; i > 0; --i)
    env.cpu.regs.greg[func.registers_offset + i - 1] = env.stack_pop();

  std::cout << "----" << std::endl;
  return true;
}

bool interpreter::handlers::setr_handler(Environment& env)
{
  int16_t reg = env.cpu.fetch_16bits_operand();
  int64_t val = env.cpu.fetch_64bits_operand();

  env.cpu.regs.greg[reg] = val;

  return true;
}
