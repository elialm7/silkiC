#ifndef chunk_h
#define chunk_h
#include "common.h"
#include "value.h"
/*
    this is used for the representaiton of our code.
    "chunk" refers to the sequences of bytecode.
    for our bytecode format, our operation code defines what type of operation
    we are dealing with.
*/
typedef enum {
  OP_CONSTANT,
  OP_RETURN,

} OP_CODE;

/*
 this struct is going to be a wrapper for the bytecode instructions.
*/
typedef struct {
  int capacity; // the numbers of elements in the array
  int count;    // how many allocations are in used.
  uint8_t *code;
  ValueArray constants;
} Chunk;

void initChunk(Chunk *chunk); // we use this function to initilize our chunk.
void freeChunk(Chunk *chunk); // for freeing our chunks
void writeChunk(Chunk *chunk,
                uint8_t byte); // for writing our chunks into our dynamic array
int addConstant(Chunk *chunk, Value value);
#endif // !chunk_h
