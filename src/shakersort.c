#include "sorting.h"


int shakersort(int *array, ptrdiff_t size) {
    int temp, swapped;

    do {
        swapped = 0;
        for (int i = 0; i < size - 1; i++) {
            if (array[i] > array[i + 1]) {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swapped = 1;
            }
        }

        if (!swapped) break;

        swapped = 0;
        for (int i = size - 2; i >= 0; i--) {
            if (array[i] > array[i + 1]) {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swapped = 1;
            }
        }
    } while (swapped);

    return 0;
}