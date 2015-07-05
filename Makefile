OUTBIN=tolk
CXX=g++
CXXFLAGS=-Wall -Wextra -std=c++14 -g3 -Wno-unused-parameter -I include -I dependencies/commons/include/ -I dependencies/network/include
TOLKFILE=dependencies/commons/src/commons/tolkfile
UTILS=dependencies/commons/src/commons/utils
NETWORK=dependencies/network/src
OBJS=src/cpu/base_cpu.o\
     src/cpu/registers.o\
     src/interpreter/opcode_manager.o\
     src/ressource/ressource.o\
     src/environment.o\
     src/interpreter/handlers/halt.o\
     src/interpreter/handlers/arithmetic.o\
     src/interpreter/handlers/stack.o\
     src/interpreter/handlers/calls.o\
     src/interpreter/handlers/parallel.o\
     src/interpreter/handlers/jumps.o\
     src/interpreter/handlers/objects.o\
     src/interpreter/handlers/register.o\
     src/args_parser.o\
     src/loader.o\
     src/main.o\
     ${TOLKFILE}/functable.o\
     ${TOLKFILE}/strtable.o\
     ${TOLKFILE}/symtable.o\
     ${TOLKFILE}/structtable.o\
     ${TOLKFILE}/tolk-file.o\
     ${NETWORK}/broadcaster.o\
     ${NETWORK}/listener.o\
     ${NETWORK}/server.o\
     ${NETWORK}/slave.o\
     ${NETWORK}/task.o\
     ${NETWORK}/service.o\
     ${NETWORK}/utils.o


.PHONY: all clean

all: tolk

tolk: $(OBJS)
	$(CXX) -o $(OUTBIN) $(OBJS) -pthread

# static linked binary
stolk: CXXFLAGS = -Wall -Wextra -static -m32 -std=c++14 -g3 -Wno-unused-parameter -I include -I dependencies/commons/include/ -I dependencies/network/include
stolk: $(OBJS)
	$(CXX) -static -m32 -o $(OUTBIN) $(OBJS) -pthread

clean:
	rm -rf $(OBJS) $(OUTBIN)
