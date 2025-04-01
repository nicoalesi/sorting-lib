#include "sorting.h"


// I forgot Bubblesort's implementation and came up with this mix
int bubblectionsort(int *array, ptrdiff_t size) {
    int temp = 0;

    for (ptrdiff_t i = 0; i < size - 1; i++) {
        for (ptrdiff_t j = i + 1; j < size; j++) {
            if (array[i] > array[j]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    return 0;
}
