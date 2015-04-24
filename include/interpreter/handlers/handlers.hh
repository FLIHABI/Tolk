#ifndef HANDLERS_HH
# define HANDLERS_HH

# include "environment.hh"

namespace interpreter
{
  namespace handlers
  {
    bool halt_handler(Environment& env);
    bool push_handler(Environment& env);
    bool pushr_handler(Environment& env);
    bool pop_handler(Environment& env);
    bool popr_handler(Environment& env);
    bool add_handler(Environment& env);
    bool sub_handler(Environment& env);
    bool mul_handler(Environment& env);
    bool div_handler(Environment& env);
    bool mod_handler(Environment& env);
  }
}

#endif /* end of include guard: HANDLERS_HH */
