#include <stdlib.h>
#include "chunk.h"



// we initilize our struct.
void initChunk(Chunk* chunk){
    chunk->capacity = 0;
    chunk->count = 0;
    chunk->code = NULL;
}

