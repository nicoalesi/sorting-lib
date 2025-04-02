#ifndef SORTING_H
#define SORTING_H

#include <errno.h>
#include <math.h>
#include <stdlib.h>

#include "arena.h"
#include "maxheap.h"

int mergesort(int *array, ptrdiff_t size);
int bubblectionsort(int *array, ptrdiff_t size);
int selectionsort(int *array, ptrdiff_t size);
int bubblesort(int *array, ptrdiff_t size);
int quicksort(int *array, ptrdiff_t size);
int heapsort(int *array, ptrdiff_t size);
int insertionsort(int *array, ptrdiff_t size);

#endif
