#include "interpreter/handlers/handlers.hh"

bool interpreter::handlers::push_handler(cpu::BaseCPU& cpu)
{
  cpu.stack_push(cpu.fetch_64bits_operand());

  return true;
}

bool interpreter::handlers::pushr_handler(cpu::BaseCPU& cpu)
{
  cpu.stack_push(cpu.regs.greg[cpu.fetch_16bits_operand()]);

  return true;
}

bool interpreter::handlers::pop_handler(cpu::BaseCPU& cpu)
{
  cpu.stack_pop();

  return true;
}

bool interpreter::handlers::popr_handler(cpu::BaseCPU& cpu)
{
  cpu.regs.greg[cpu.fetch_16bits_operand()] = cpu.stack_pop();

  return true;
}
