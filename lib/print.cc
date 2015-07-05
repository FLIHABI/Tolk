#include <iostream>
#include "print.hh"

extern "C" void print_int(Environment& env)
{
    uint64_t args = env.stack_pop();
    uint64_t value = env.stack_pop();
    for (uint64_t  i = 1; i < args; i++)
        env.stack_pop();

    std::cout << value;
}

extern "C" void print_newline(Environment& env)
{
    uint64_t args = env.stack_pop();

    for (uint64_t i = 0; i < args; i++)
        env.stack_pop();

    std::cout << std::endl;
}
