#include "linkedlist.h"


// Linked list add
int lladd(llist_t *list, int value, arena_t *arena) {
    node_t *ptr = aalloc(arena, 1, node_t);
    if (!ptr) return ENOMEM;

    if (!(list->head)) {
        list->head = ptr;
        list->tail = list->head;
    } else {
        list->tail->next = ptr;
        list->tail = list->tail->next;
    }

    list->tail->value = value;
    return 0;
}
