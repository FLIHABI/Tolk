#include <cstring>

#include "args_parser.hh"

args_datas parse_args(int argc, char* argv[])
{
  args_datas datas
  {
    .mode = network::SERVER,
    .filename = "",
    .libs = std::vector<std::string>()
  };
  bool mode = false;
  bool filename = false;

  for (int i = 1; i < argc; ++i)
  {
    if (argv[i][0] == '-')
    {
      if (mode)
        throw std::invalid_argument("Duplicate mode");

      if (argv[i][1] == '-')
      {
        if (!strcmp(argv[i] + 2, "client"))
          datas.mode = network::CLIENT;
        else if (strcmp(argv[i] + 2, "server"))
          throw std::invalid_argument("Bad mode");
      }
      else
      {
        if (!strcmp(argv[i] + 1, "c"))
          datas.mode = network::CLIENT;
        else if (strcmp(argv[i] + 1, "s"))
          throw std::invalid_argument("Bad mode");
      }

      mode = true;
    }
    else
    {
      if (filename)
          datas.libs.emplace_back(argv[i]);
      else
      {
          datas.filename = argv[i];
          filename = true;
      }
    }
  }

  return datas;
}
