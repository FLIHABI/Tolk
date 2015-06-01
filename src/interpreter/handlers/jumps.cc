#include <cstdint>

#include "interpreter/handlers/handlers.hh"

bool interpreter::handlers::jmp_handler(Environment& env)
{
  env.cpu.regs.PC += env.cpu.fetch_16bits_operand();

  return true;
}

bool interpreter::handlers::je_handler(Environment& env)
{
  int16_t offset = env.cpu.fetch_16bits_operand();
  int64_t value2 = env.stack_pop();
  int64_t value1 = env.stack_pop();

  if (value1 == value2)
    env.cpu.regs.PC += offset;

  return true;
}

bool interpreter::handlers::jl_handler(Environment& env)
{
  int16_t offset = env.cpu.fetch_16bits_operand();

  int64_t value2 = env.stack_pop();
  int64_t value1 = env.stack_pop();

  if (value1 < value2)
    env.cpu.regs.PC += offset;

  return true;
}

bool interpreter::handlers::jg_handler(Environment& env)
{
  int16_t offset = env.cpu.fetch_16bits_operand();

  int64_t value2 = env.stack_pop();
  int64_t value1 = env.stack_pop();

  if (value1 > value2)
    env.cpu.regs.PC += offset;

  return true;
}

bool interpreter::handlers::jne_handler(Environment& env)
{
  int16_t offset = env.cpu.fetch_16bits_operand();

  int64_t value2 = env.stack_pop();
  int64_t value1 = env.stack_pop();

  if (value1 != value2)
    env.cpu.regs.PC += offset;

  return true;
}

bool interpreter::handlers::jle_handler(Environment& env)
{
  int16_t offset = env.cpu.fetch_16bits_operand();

  int64_t value2 = env.stack_pop();
  int64_t value1 = env.stack_pop();

  if (value1 <= value2)
    env.cpu.regs.PC += offset;

  return true;
}

bool interpreter::handlers::jge_handler(Environment& env)
{
  int16_t offset = env.cpu.fetch_16bits_operand();

  int64_t value2 = env.stack_pop();
  int64_t value1 = env.stack_pop();

  if (value1 >= value2)
    env.cpu.regs.PC += offset;

  return true;
}

bool interpreter::handlers::jmps_handler(Environment& env)
{
  env.cpu.regs.PC += env.stack_pop();

  return true;
}
