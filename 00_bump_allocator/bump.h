#ifndef BUMP_H
#define BUMP_H

#include <stddef.h> // size_t

// Initialize the heap of the bump allocator
//
// Receive a block of memory reserved (for example, with malloc o mmap).
void bump_init(void *memory, size_t size);

// Allocates memory linearly
//
// Do not suport free() -> only move the pointer.
void *bump_alloc(size_t size);

// Reset the entire heap (opcional).
//
// Useful if you want to reuse all the arena.
void bump_reset();

#endif
