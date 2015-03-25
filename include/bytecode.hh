#ifndef BYTECODE_HH
# define BYTECODE_HH

/*
------------------------------------------------
VM management
------------------------------------------------
*/

#define HALT 0x00

/*
------------------------------------------------
Stack and register management
------------------------------------------------
*/

#define POP 0x13
#define PUSH 0x17
#define PUSHR 0x18
#define POPR 0x19

/*
------------------------------------------------
Arithmetic
------------------------------------------------
*/

#define ADD 0x20
#define SUB 0x21
#define MUL 0x22
#define DIV 0x23
#define MOD 0x24

/*
------------------------------------------------
Tests
------------------------------------------------
*/

#define CMP 0x30

/*
------------------------------------------------
Branching
------------------------------------------------
*/

#define CALL 0x40
#define CALLR 0x49
#define RET 0x41
#define JMP 0x42
#define JE 0x43
#define JL 0x44
#define JG 0x45
#define JNE 0x46
#define JLE 0x47
#define JGE 0x48

/*
------------------------------------------------
Object management
------------------------------------------------
*/

#define CREATE 0x50
#define DELETE 0x51

#endif /* end of include guard: BYTECODE_HH */
