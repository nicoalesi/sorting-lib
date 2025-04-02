#include "sorting.h"


// Wrapper that can be called by the user
int binaryinsertionsort(int *array, ptrdiff_t size) {
    binarysort(array, size);

    return 0;
}


// Like Insertionsort but with binary search
int binarysort(int *array, ptrdiff_t size) {
    int value;
    ptrdiff_t start, center, end;

    for (ptrdiff_t i = 1; i < size; i++) {
        value = array[i];
        start = 0;
        end = i - 1;

        while (start <= end) {
            center = start + (end - start) / 2;
            if (array[center] < value) {
                start = center + 1;
            } else {
                end = center - 1;
            }
        }

        for (ptrdiff_t j = i - 1; j >= start; j--) {
            array[j + 1] = array[j];
        }

        array[start] = value;
    }

    return 0;
}
