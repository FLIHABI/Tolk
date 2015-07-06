#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "random.hh"

extern "C" void get_random(Environment& env)
{
    uint64_t args = env.stack_pop();
    uint64_t mod = env.stack_pop();
    uint64_t id = env.stack_pop();

    for (uint64_t i = 2; i < args; i++)
        env.stack_pop();

    (*env.res.get_object(id))[0] = rand() % mod;
}

extern "C" void init_random(Environment& env)
{
    uint64_t args = env.stack_pop();

    for (uint64_t i = 0; i < args; i++)
        env.stack_pop();

    srand(time(NULL));
}
