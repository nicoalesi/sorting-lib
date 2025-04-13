#include "sorting.h"


// Insertion sort for bucket (linked list)
// After using this function the liked list's tail is no longer correct
int sortbucket(llist_t *list) {
    if (!list->head || !list->head->next) return 0;

    node_t *sorted = NULL;
    node_t *curr = list->head;
    node_t *next, *runner;

    while (curr) {
        next = curr->next;

        // Check if the sorted sub-list is empty or
        // if the current element is less than the smallest sorted element
        if (!sorted || sorted->value >= curr->value) {
            // Insert at the beginning
            curr->next = sorted;
            sorted = curr;
        } else {
            // Insert in the middle / at the end
            runner = sorted;
            // Find the right spot
            while (runner->next && runner->next->value < curr->value) {
                runner = runner->next;
            }
            // Insert current after runner
            curr->next = runner->next;
            runner->next = curr;
        }

        curr = next;
    }

    list->head = sorted;
    return 0;
}


// Actual implementation of bucketsort
int inner_bucketsort(int *array, int min, \
                     int num_buckets, arena_t *arena, ptrdiff_t size) {
    ptrdiff_t bucket;
    llist_t *buckets = aalloc(arena, num_buckets, llist_t);
    if (!buckets) return ENOMEM;

    for (ptrdiff_t i = 0; i < size; i++) {
        bucket = (array[i] - min) / 10;
        if(lladd(&buckets[bucket], array[i], arena)) return ENOMEM;
    }

    ptrdiff_t k = 0;
    node_t *current_node;

    for (ptrdiff_t i = 0; i < num_buckets; i++) {
        sortbucket(&buckets[i]);
        // After 'sortbucket' the linked list's tail is not preserved
        // to save n iterations
        current_node = buckets[i].head;
        while (current_node) {
            array[k++] = current_node->value;
            current_node = current_node->next;
        }
    }
    
    return 0;
}


// Wrapper called by the user
int bucketsort(int *array, ptrdiff_t size) {
    if (size < 1) return 0;

    int min = array[0];
    int max = array[0];

    for (ptrdiff_t i = 1; i < size; i++) {
        if (array[i] > max) max = array[i];
        if (array[i] < min) min = array[i];
    }

    int num_buckets = (max - min) / 10 + 1;
    // Size + number of buckets + 1 to make sure there are no problems with padding
    ptrdiff_t arena_size = \
        (ptrdiff_t)(sizeof(node_t) * size + sizeof(llist_t) * (num_buckets + 1));
    char *arena_start = malloc(arena_size);
    if (!arena_start) return ENOMEM;
    arena_t arena = anew(arena_start, arena_size);

    if (inner_bucketsort(array, min, num_buckets, &arena, size)) return ENOMEM;

    free(arena_start);
    return 0;
}
