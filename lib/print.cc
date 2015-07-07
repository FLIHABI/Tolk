#include <fstream>
#include <string>
#include "print.hh"

static std::ofstream aux;

extern "C" void print_int(Environment& env)
{
    uint64_t args = env.stack_pop();
    uint64_t value = env.stack_pop();
    for (uint64_t  i = 1; i < args; i++)
        env.stack_pop();

    aux << value;
}

extern "C" void print_newline(Environment& env)
{
    uint64_t args = env.stack_pop();

    for (uint64_t i = 0; i < args; i++)
        env.stack_pop();


    aux << std::endl;
}

extern "C" void print_string(Environment& env)
{
    uint64_t args = env.stack_pop();
    uint64_t id = env.stack_pop();
    for (uint64_t  i = 1; i < args; i++)
        env.stack_pop();

    aux << env.res.get_string(id);
}

extern "C" void log_(Environment& env)
{
    static unsigned counter = 0;
    uint64_t args = env.stack_pop();

    aux.close();

    for (uint64_t i = 0; i < args; i++)
        env.stack_pop();

    aux.open("file" + std::to_string(counter));
    ++counter;
}
