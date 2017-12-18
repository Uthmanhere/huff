#ifndef __HEAP_C
#define __HEAP_C

#include <stdlib.h>

#include "struct/HNode.c"

void max_heapify(h_node **,size_t, int);
void build_max_heap(h_node **, size_t);
void heapsort(h_node **, size_t);


#endif

