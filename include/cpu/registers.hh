#ifndef REGISTERS_HH
# define REGISTERS_HH

# include <vector>

namespace cpu
{
  class Registers
  {
    public:
      Registers(unsigned gen_reg);

      unsigned PC;
      std::vector<long long> greg;
  };
}

#endif /* end of include guard: REGISTERS_HH */
