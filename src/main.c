#include "common.h"
#include <stdio.h>
#include "chunk.h"

int main(int argc, char const *argv[]){

    printf("hello world \n");
    Chunk ch;

    initChunk(&ch);

    ch.capacity = 30;

    printf("%d", ch.capacity);
    /* code */
    return 0;
}
