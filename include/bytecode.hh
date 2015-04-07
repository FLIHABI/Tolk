#ifndef BYTECODE_HH
# define BYTECODE_HH

/*
------------------------------------------------
VM management
------------------------------------------------
*/

#define OP_HALT 0x00

/*
------------------------------------------------
Stack and register management
------------------------------------------------
*/

#define OP_POP 0x13
#define OP_PUSH 0x17
#define OP_PUSHR 0x18
#define OP_POPR 0x19

/*
------------------------------------------------
Arithmetic
------------------------------------------------
*/

#define OP_ADD 0x20
#define OP_SUB 0x21
#define OP_MUL 0x22
#define OP_DIV 0x23
#define OP_MOD 0x24

/*
------------------------------------------------
Tests
------------------------------------------------
*/

#define OP_CMP 0x30

/*
------------------------------------------------
Branching
------------------------------------------------
*/

#define OP_CALL 0x40
#define OP_CALLR 0x49
#define OP_RET 0x41
#define OP_JMP 0x42
#define OP_JE 0x43
#define OP_JL 0x44
#define OP_JG 0x45
#define OP_JNE 0x46
#define OP_JLE 0x47
#define OP_JGE 0x48

/*
------------------------------------------------
Object management
------------------------------------------------
*/

#define OP_CREATE 0x50
#define OP_DELETE 0x51

#endif /* end of include guard: BYTECODE_HH */
