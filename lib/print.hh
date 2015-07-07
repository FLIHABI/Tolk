#ifndef PRINT_HH
# define PRINT_HH

# include "environment.hh"

extern "C" void print_int(Environment& env);
extern "C" void print_newline(Environment& env);
extern "C" void print_string(Environment& env);
extern "C" void log_(Environment& env);

#endif /* PRINT_HH */
