#ifndef chunk_h
#define chunk_h
#include "common.h"

/*
    this is used for the representaiton of our code. 
    "chunk" refers to the sequences of bytecode. 
    for our bytecode format, our operation code defines what type of operation
    we are dealing with. 
*/
typedef enum {
    OP_RETURN
}OP_CODE;

/*
 this struct is going to be a wrapper for the bytecode instructions.
*/
typedef struct {
    uint8_t* code;
}Chunk;

#endif // !chunk_h
