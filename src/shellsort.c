#include "sorting.h"

int shellsort(int *array, ptrdiff_t size) {
    // Ciura's gap sequence
    int sequence[8] = {701, 301, 132, 57, 23, 10, 4, 1};
    int sequence_size = 8;
    int temp, gap;
    ptrdiff_t j;

    for (ptrdiff_t k = 0; k < sequence_size; k++) {
        gap = sequence[k];

        for (ptrdiff_t i = gap; i < size; i++) {
            temp = array[i];

            for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
                array[j] = array[j - gap];
            }

            array[j] = temp;
        }
    }

    return 0;
}
