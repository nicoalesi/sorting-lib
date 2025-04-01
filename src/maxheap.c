#include "maxheap.h"


// Convert an array in a heap
int heapify(int *array, ptrdiff_t size) {
    for (ptrdiff_t i = size / 2 - 1; i >= 0; i--) {
        sift_down(array, i, size);
    }

    return 0;
}


int extract_max(int *heap, ptrdiff_t size) {
    int value = heap[0];
    heap[0] = heap[size - 1];
    sift_down(heap, 0, size - 1);

    return value;
}


// Bring a node down to its place inside the tree
int sift_down(int *heap, ptrdiff_t index, ptrdiff_t size) {
    int temp;
    ptrdiff_t largest = index;
    // No overflow because index <= size / 2 - 1
    ptrdiff_t left = 2 * index + 1;
    ptrdiff_t right = 2 * index + 2;

    if (left < size && heap[left] > heap[largest]) largest = left;
    if (right < size && heap[right] > heap[largest]) largest = right;

    if (largest != index) {
        temp = heap[index];
        heap[index] = heap[largest];
        heap[largest] = temp;
        sift_down(heap, largest, size);
    }

    return 0;
}
