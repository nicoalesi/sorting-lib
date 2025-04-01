#include "sorting.h"


int heapsort(int *array, ptrdiff_t size) {
    heapify(array, size);
    while (size > 1) {
        array[size - 1] = extract_max(array, size);
        size--;
    }

    return 0;
}
