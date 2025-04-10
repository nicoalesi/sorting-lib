#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>

#include "arena.h"

/*
 * Single node to construct any linked list 
 *
 */
typedef struct node_t {
    int value;
    struct node_t *next;
} node_t;

typedef struct {
    node_t *head;
    node_t *tail;
} llist_t;

int lladd(llist_t *list, int value, arena_t *arena);

#endif
