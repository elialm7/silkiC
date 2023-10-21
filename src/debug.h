#ifndef silki_debug_h
#define silki_debug_h
#include "chunk.h"

void disassambleChunk(Chunk *chunk, const char* name );
int disassambleInstruction(Chunk* chunk, int offset);

#endif // !silki_debuj_h