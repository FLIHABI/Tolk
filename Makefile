OUTBIN=tolk
CXX=g++
CXXFLAGS=-Wall -Wextra -std=c++14 -g -Wno-unused-parameter -I include -I dependencies/commons/include/
OBJS=src/cpu/base_cpu.o\
     src/cpu/registers.o\
     src/interpreter/opcode_manager.o\
     src/environment.o\
     src/interpreter/handlers/halt.o\
     src/interpreter/handlers/arithmetic.o\
     src/interpreter/handlers/stack.o\
     src/loader.o\
     src/main.o

.PHONY: all clean

all: tolk

tolk: $(OBJS)
	$(CXX) -o $(OUTBIN) $(OBJS)

# static linked binary
stolk: $(OBJS)
	$(CXX) -o $(OUTBIN) -static $(OBJS)

clean:
	rm -rf $(OBJS) $(OUTBIN)
