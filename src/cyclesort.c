#include "sorting.h"


int cyclesort(int *array, ptrdiff_t size) {
    ptrdiff_t position;
    int temp, element;

    for (int i = 0; i < size - 1; i++) {
        element = array[i];
        position = i;

        for (int j = i + 1; j < size; j++) {
            if (array[j] < element) position++;
        }

        if (position == i) continue;
        while (element == array[position]) position++;

        temp = element;
        element = array[position];
        array[position] = temp;

        while (position != i) {
            position = i;
            for (int j = i + 1; j < size; j++) {
                if (array[j] < element) position++;
            }

            while (element == array[position]) position++;
            temp = element;
            element = array[position];
            array[position] = temp;
        }
    }

    return 0;
}