#ifndef silki_memory_h
#define silki_memory_h
#include "common.h"
/*
    this macro is for growing a capacity. it just doubles the capacity. 
*/
#define GROW_CAPACITY(capacity) \
    ((capacity)<8?8:(capacity)*2)

/*
 this macro is for reallocating the array. calls the function reallocate and then casts it to its correct type. 
*/
#define GROW_ARRAY(type, pointer, oldCount, newCount) \
    (type*)reallocate(pointer, sizeof(type) * (oldCount), \
        sizeof(type) * (newCount))

/*
In this function is where all the magic happens, this is in charge of reallocating the memory. 
*/

#define FREE_ARRAY(type, pointer, oldcount)\
reallocate(pointer, sizeof(type) * oldcount,0)

void* reallocate(void* pointer, size_t oldSize, size_t newSize);
#endif // !silki_memory_h#def