#include "arena.h"


// Function to 'allocate' memory taken from the arena
void *arena_alloc(arena_t *arena,
                  ptrdiff_t count, ptrdiff_t size, ptrdiff_t align) {

    // Trick to calculate the padding, it is equivalent to
    // padding = align - (address - align)
    ptrdiff_t padding = -(uintptr_t)arena->start & (align - 1);
    ptrdiff_t available_space = arena->end - arena->start - padding;

    if (available_space < 0 || count > available_space / size) {
        return NULL;
    }

    void *p = arena->start + padding;
    arena->start += padding + count * size;

    // Return a pointer to the 'allocated' memory
    return memset(p, 0, count * size);
}


// Function to 'free' memory previously take from the arena
void arena_dealloc(arena_t *arena, ptrdiff_t count, ptrdiff_t size) {
    ptrdiff_t allocated_space = arena->start - arena->original_start;

    if (count <= allocated_space / size) {
        arena->start -= count * size;
    }

    return;
}
