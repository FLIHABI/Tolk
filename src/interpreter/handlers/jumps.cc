#include <cstdint>

#include "interpreter/handlers/handlers.hh"

bool jmp_handler(Environment& env)
{
  env.cpu.regs.PC += env.cpu.fetch_16bits_operand();

  return true;
}

bool je_handler(Environment& env)
{
  int16_t offset = env.cpu.fetch_16bits_operand();
  int64_t value2 = env.stack_pop();
  int64_t value1 = env.stack_pop();

  if (value1 == value2)
    env.cpu.regs.PC += offset;

  return true;
}

bool jl_handler(Environment& env)
{
  int16_t offset = env.cpu.fetch_16bits_operand();

  int64_t value2 = env.stack_pop();
  int64_t value1 = env.stack_pop();

  if (value1 < value2)
    env.cpu.regs.PC += offset;

  return true;
}

bool jg_handler(Environment& env)
{
  int16_t offset = env.cpu.fetch_16bits_operand();

  int64_t value2 = env.stack_pop();
  int64_t value1 = env.stack_pop();

  if (value1 > value2)
    env.cpu.regs.PC += offset;

  return true;
}

bool jne_handler(Environment& env)
{
  int16_t offset = env.cpu.fetch_16bits_operand();

  int64_t value2 = env.stack_pop();
  int64_t value1 = env.stack_pop();

  if (value1 != value2)
    env.cpu.regs.PC += offset;

  return true;
}

bool jle_handler(Environment& env)
{
  int16_t offset = env.cpu.fetch_16bits_operand();

  int64_t value2 = env.stack_pop();
  int64_t value1 = env.stack_pop();

  if (value1 <= value2)
    env.cpu.regs.PC += offset;

  return true;
}

bool jge_handler(Environment& env)
{
  int16_t offset = env.cpu.fetch_16bits_operand();

  int64_t value2 = env.stack_pop();
  int64_t value1 = env.stack_pop();

  if (value1 >= value2)
    env.cpu.regs.PC += offset;

  return true;
}
