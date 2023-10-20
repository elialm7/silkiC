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
    int capacity; // the numbers of elements in the array
    int count; // how many allocations are in used.
    uint8_t* code;
}Chunk;

void initChunk(Chunk* chunk); // we use this function to initilize our chunk.

#endif // !chunk_h
