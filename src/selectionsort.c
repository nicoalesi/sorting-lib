#include "sorting.h"


int selectionsort(int *array, ptrdiff_t size) {
    int min_index, temp;

    for (ptrdiff_t i = 0; i < size - 1; i++) {
        min_index = i;

        for (ptrdiff_t j = i + 1; j < size; j++) {
            if (array[j] < array[min_index]) min_index = j;
        }

        temp = array[i];
        array[i] = array[min_index];
        array[min_index] = temp;
    }

    return 0;
}
