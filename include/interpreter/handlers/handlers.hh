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
    bool call_handler(Environment& env);
    bool callr_handler(Environment& env);
    bool ret_handler(Environment& env);
    bool save_handler(Environment& env);
    bool restore_handler(Environment& env);
    bool setr_handler(Environment& env);
    bool create_handler(Environment& env);
    bool delete_handler(Environment& env);
    bool read_handler(Environment& env);
    bool write_handler(Environment& env);
    bool jmp_handler(Environment& env);
    bool je_handler(Environment& env);
    bool jl_handler(Environment& env);
    bool jg_handler(Environment& env);
    bool jne_handler(Environment& env);
    bool jle_handler(Environment& env);
    bool jge_handler(Environment& env);
    bool jmps_handler(Environment& env);
  }
}

#endif /* end of include guard: HANDLERS_HH */
