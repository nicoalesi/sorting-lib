#include "sorting.h"
#include <stdio.h>

int countingsort(int *array, ptrdiff_t size) {
    if (size < 1) return -1;

    int min = array[0];
    int max = array[0];
    int j = 0;

    for (ptrdiff_t i = 1; i < size; i++) {
        if (array[i] > max) max = array[i];
        if (array[i] < min) min = array[i];
    }

    ptrdiff_t temp_size = max - min + 1;
    int *temp = (int *)calloc(temp_size, sizeof(int));
    if (!temp) return ENOMEM;

    for (ptrdiff_t i = 0; i < size; i++) temp[array[i] - min]++;

    for (ptrdiff_t i = 0; i < temp_size; i++) {
        while (temp[i] > 0) {
            array[j++] = i + min;
            temp[i]--;
        }
    }

    free(temp);
    return 0;
}
