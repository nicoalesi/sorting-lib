#include "sorting.h"


int bubblesort(int *array, ptrdiff_t size) {
    int temp;

    for (ptrdiff_t i = 0; i < size - 1; i++) {
        for (ptrdiff_t j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    return 0;
}
