#ifndef ARGS_PARSER_HH
# define ARGS_PARSER_HH

# include <string>

# include "service.hh"

struct args_datas
{
  network::NetworkMode mode;
  std::string filename;
};

args_datas parse_args(int argc, char* argv[]);

#endif /* end of include guard: ARGS_PARSER_HH */
