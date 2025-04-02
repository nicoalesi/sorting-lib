#include "sorting.h"


int insertionsort(int *array, ptrdiff_t size) {
    int value, j;

    for (ptrdiff_t i = 1; i < size; i++) {
        value = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > value) {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = value;
    }

    return 0;
}
