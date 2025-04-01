#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <stdlib.h>

int heapify(int *array, ptrdiff_t size);
int extract_max(int *heap, ptrdiff_t size);
int sift_down(int *heap, ptrdiff_t index, ptrdiff_t size);

#endif
