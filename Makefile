OUTBIN=tolk
CXX=g++
CXXFLAGS=-Wall -Wextra -std=c++14 -I include
OBJS=src/cpu/base_cpu.o\
     src/cpu/cpu.o\
     src/cpu/registers.o\
     src/interpreter/opcode_manager.o

.PHONY: all clean

all: tolk

tolk: $(OBJS)
	$(CXX) -o $(OUTBIN) $(OBJS)

clean:
	rm -rf $(OBJS) $(OUTBIN)
