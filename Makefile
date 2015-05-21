OUTBIN=tolk
CXX=g++
CXXFLAGS=-Wall -Wextra -std=c++14 -g3 -Wno-unused-parameter -I include -I dependencies/commons/include/
TOLKFILE=dependencies/commons/src/commons/tolkfile
OBJS=src/cpu/base_cpu.o\
     src/cpu/registers.o\
     src/interpreter/opcode_manager.o\
     src/ressource/ressource.o\
     src/environment.o\
     src/interpreter/handlers/halt.o\
     src/interpreter/handlers/arithmetic.o\
     src/interpreter/handlers/stack.o\
     src/interpreter/handlers/calls.o\
     src/interpreter/handlers/jumps.o\
     src/interpreter/handlers/objects.o\
     src/interpreter/handlers/register.o\
     src/loader.o\
     src/main.o\
     ${TOLKFILE}/functable.o\
     ${TOLKFILE}/strtable.o\
     ${TOLKFILE}/symtable.o\
     ${TOLKFILE}/tolk-file.o

.PHONY: all clean

all: tolk

tolk: $(OBJS)
	$(CXX) -o $(OUTBIN) $(OBJS)

# static linked binary
stolk: $(OBJS)
	$(CXX) -o $(OUTBIN) -static $(OBJS)

clean:
	rm -rf $(OBJS) $(OUTBIN)
