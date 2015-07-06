#ifndef RANDOM_HH
# define RANDOM_HH

# include "environment.hh"

extern "C" void get_random(Environment& env);
extern "C" void init_random(Environment& env);

#endif /* RANDOM_HH */
