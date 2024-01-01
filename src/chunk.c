#include "chunk.h"
#include "memory.h"
#include "value.h"
#include <stdint.h>
#include <stdlib.h>

// we initilize our struct.
void initChunk(Chunk *chunk) {
  chunk->capacity = 0;
  chunk->count = 0;
  chunk->code = NULL;
  initValueArray(&chunk->constants);
}
// we write our chunk in our dinamic array.
void writeChunk(Chunk *chunk, uint8_t byte) {
  if (chunk->capacity < chunk->count + 1) {
    int oldcapacity = chunk->capacity;
    chunk->capacity = GROW_CAPACITY(oldcapacity);
    chunk->code =
        GROW_ARRAY(uint8_t, chunk->code, oldcapacity, chunk->capacity);
  }
  chunk->code[chunk->count] = byte;
  chunk->count++;
}
/* this methods frees the chunk array from memory, it doesn't delete it from
 * memory just reallocates it.
 */
void freeChunk(Chunk *chunk) {
  FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
  freeValueArray(&chunk->constants);
  initChunk(chunk);
}

int addConstant(Chunk *chunk, Value value) {
  writeValueArray(&chunk->constants, value);
  return chunk->constants.count - 1;
}
