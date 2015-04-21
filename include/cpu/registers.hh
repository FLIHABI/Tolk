#ifndef REGISTERS_HH
# define REGISTERS_HH

# include <vector>
# include <cstdint>

namespace cpu
{
  class Registers
  {
    public:
      Registers(unsigned gen_reg);

      unsigned PC;
      std::vector<int64_t> greg;
  };
}

#endif /* end of include guard: REGISTERS_HH */
