#include <stdio.h>

#include "debug.h"


void disassambleChunk(Chunk *chunk, const char *name){
        printf("== %s ==\n" , name);
        for(int offset = 0;offset < chunk->count;){
            offset = disassambleInstruction(chunk, offset);
        }
}
static int simpleInstruction(const char *text, int offset){
    printf("%s ", text);
    return offset + 1;

}
int disassambleInstruction(Chunk *chunk, int offset){
    printf("%04d ", offset);

    uint8_t instruction = chunk->code[offset];
    switch (instruction) {
        case OP_RETURN:
            return simpleInstruction("OP_RETURN", offset);
            default: 
                printf("Unknown operation code : %d\n", instruction);
                return offset + 1;
    }
}

