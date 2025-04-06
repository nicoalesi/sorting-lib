#include "sorting.h"


int combsort(int *array, ptrdiff_t size) {
    ptrdiff_t gap = size;
    int temp, swapped;

    if (size < 1) return 0;

    do {
        if (gap > 1) {
            gap = gap / 1.3;
            // Avoid slowdown, 9 and 10 would shrink to less effective gaps later
            if (gap == 10 || gap == 9) gap = 11;
        }

        swapped = 0;
        for (int i = 0; i < size - gap; i += gap) {
            if (array[i] > array[i + gap]) {
                temp = array[i];
                array[i] = array[i + gap];
                array[i + gap] = temp;
                swapped = 1;
            }
        }
    } while (gap > 1 || swapped);

    return 0;
}