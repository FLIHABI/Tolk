OUTBIN=tolk
CXX=g++
CXXFLAGS=-Wall -Wextra -std=c++14 -g -I include -I dependencies/commons/include/
OBJS=src/cpu/base_cpu.o\
     src/cpu/cpu.o\
     src/cpu/registers.o\
     src/interpreter/opcode_manager.o\
     src/interpreter/handlers/halt.o\
     src/loader.o\
     src/main.o

.PHONY: all clean

all: tolk

tolk: $(OBJS)
	$(CXX) -o $(OUTBIN) $(OBJS)

clean:
	rm -rf $(OBJS) $(OUTBIN)
