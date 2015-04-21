#include "interpreter/handlers/handlers.hh"

bool interpreter::handlers::add_handler(cpu::BaseCPU& cpu)
{
  long long value2 = cpu.stack_pop();
  long long value1 = cpu.stack_pop();

  cpu.stack_push(value1 + value2);

  return true;
}

bool interpreter::handlers::sub_handler(cpu::BaseCPU& cpu)
{
  long long value2 = cpu.stack_pop();
  long long value1 = cpu.stack_pop();

  cpu.stack_push(value1 - value2);

  return true;
}

bool interpreter::handlers::mul_handler(cpu::BaseCPU& cpu)
{
  long long value2 = cpu.stack_pop();
  long long value1 = cpu.stack_pop();

  cpu.stack_push(value1 * value2);

  return true;
}

bool interpreter::handlers::div_handler(cpu::BaseCPU& cpu)
{
  long long value2 = cpu.stack_pop();
  long long value1 = cpu.stack_pop();

  cpu.stack_push(value1 / value2);

  return true;
}

bool interpreter::handlers::mod_handler(cpu::BaseCPU& cpu)
{
  long long value2 = cpu.stack_pop();
  long long value1 = cpu.stack_pop();

  cpu.stack_push(value1 % value2);

  return true;
}
