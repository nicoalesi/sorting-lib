#include "sorting.h"


// Function to merge two sub-arrays
int merge(int *array, ptrdiff_t start,
          ptrdiff_t center, ptrdiff_t end, arena_t *arena) {

    ptrdiff_t i = start;
    ptrdiff_t j = center + 1;
    ptrdiff_t k = 0;

    int *temp_array = aalloc(arena, end - start + 1, int);
    if (!temp_array) return ENOMEM;

    while (i <= center && j <= end) {
        if (array[i] <= array[j]) {
            temp_array[k++] = array[i++];
        } else {
            temp_array[k++] = array[j++];
        }
    }

    while (i <= center) temp_array[k++] = array[i++];
    while (j <= end) temp_array[k++] = array[j++];

    for (k = start; k <= end; k++) array[k] = temp_array[k - start];

    adealloc(arena, end - start + 1, int);
    return 0;
}


// Mergesort implementation
int inner_mergesort(int *array, ptrdiff_t start, ptrdiff_t end, arena_t *arena) {
    if (start < end) {
        ptrdiff_t center = start + (end - start) / 2;
        if (inner_mergesort(array, start, center, arena)) return ENOMEM;
        if (inner_mergesort(array, center + 1, end, arena)) return ENOMEM;
        if (merge(array, start, center, end, arena)) return ENOMEM;
    }
    
    return 0;
}


// Wrapper called by the user
int mergesort(int *array, ptrdiff_t size) {
    // Size + 1 to make sure there are no problems with padding
    ptrdiff_t arena_size = (ptrdiff_t)(sizeof(int) * (size + 1));
    char *arena_start = malloc(arena_size);
    if (!arena_start) return ENOMEM;
    arena_t arena = anew(arena_start, arena_size);

    if (inner_mergesort(array, 0, size - 1, &arena)) return ENOMEM;

    free(arena_start);
    return 0;
}
