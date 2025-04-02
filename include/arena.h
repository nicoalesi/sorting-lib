#ifndef ARENA_H
#define ARENA_H

#include <stdlib.h>
#include <string.h>

#define anew(start, size) {start, start, start + size}
#define aalloc(arena, count, type) \
        (type *)arena_alloc(arena, count, sizeof(type), _Alignof(type))
#define adealloc(arena, count, type) \
        arena_dealloc(arena, count, sizeof(type))

/*
 *  Memory pool (arena) from which we can allocate memory for other variables
 *  Start: start of the currently available block of memory
 *  End: end of the currently available block of memory
 *
 */
typedef struct {
    char *original_start;
    char *start;
    char *end;
} arena_t;

void *arena_alloc(arena_t *a, ptrdiff_t count, ptrdiff_t size, ptrdiff_t align);
void arena_dealloc(arena_t *arena, ptrdiff_t count, ptrdiff_t size);

#endif
