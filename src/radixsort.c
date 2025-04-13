#include "sorting.h"


// Actual implementation
int inner_radixsort(int *array, ptrdiff_t size, arena_t *arena) {
    int max = array[0];
    int digits = 0;
    llist_t *buckets = aalloc(arena, 10, llist_t);
    if (!buckets) return ENOMEM;

    node_t *current_node;
    ptrdiff_t w;
    int bucket;

    for (ptrdiff_t i = 1; i < size; i++) {
        if (array[i] > max) max = array[i];
    }

    while (max > 0) {
        max /= 10;
        digits++;
    }

    for (int i = 1; i <= digits; i++) {
        w = 0;

        for (ptrdiff_t j = 0; j < size; j++) {
            bucket = array[j] % (int)pow(10, i) / (int)pow(10, i - 1);
            if (lladd(&buckets[bucket], array[j], arena)) return ENOMEM;
        }

        for (ptrdiff_t k = 0; k < 10; k++) {
            current_node = buckets[k].head;
            while (current_node) {
                array[w++] = current_node->value;
                current_node = current_node->next;
            }
        }

        // Erase current linked lists for next round
        memset(buckets, 0, sizeof(llist_t) * 10);
        // Reuse space for next round
        adealloc(arena, size, node_t);
    }

    return 0;
}


// Wrapper called by the user
int radixsort(int *array, ptrdiff_t size) {
    if (size < 1) return 0;

    // Size + number of buckets + 1 to make sure there are no problems with padding
    ptrdiff_t arena_size = \
        (ptrdiff_t)(sizeof(node_t) * size + sizeof(llist_t) * (10 + 1));
    char *arena_start = malloc(arena_size);
    if (!arena_start) return ENOMEM;
    arena_t arena = anew(arena_start, arena_size);

    if (inner_radixsort(array, size, &arena)) return ENOMEM;

    free(arena_start);
    return 0;
}
