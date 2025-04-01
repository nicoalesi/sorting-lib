#include "sorting.h"


// Choose pivot and rearrange the array
int pivot(int *array, ptrdiff_t start, ptrdiff_t end) {
    int temp;
    int x = array[start];
    ptrdiff_t k = start;

    // Create a sub-array with all the values smaller than pivot's value
    for (ptrdiff_t i = start; i <= end; i++) {
        if (array[i] < x) {
            k++;
            temp = array[i];
            array[i] = array[k];
            array[k] = temp;
        }
    }

    // Place pivot at the end of the sub-array
    array[start] = array[k];
    array[k] = x;
    return k;
}


// Real Quicksort implementation
int inner_quicksort(int *array, ptrdiff_t start, ptrdiff_t end) {
    if (start < end) {
        ptrdiff_t k = pivot(array, start, end);
        inner_quicksort(array, start, k - 1);
        inner_quicksort(array, k + 1, end);
    }
    
    return 0;
}


// Wrapper called by the user
int quicksort(int *array, ptrdiff_t size) {
    inner_quicksort(array, 0, size - 1);

    return 0;
}
