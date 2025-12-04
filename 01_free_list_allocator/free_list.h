#ifndef FREE_LIST_H
#define FREE_LIST_H

#include <stddef.h>

// Header for each block on the arena
typedef struct BlockHeader {
    size_t size;                 // Size of the block (DATA)
    int free;                    // 1 = free, 0 = fill
    struct BlockHeader *next;    // Next free block (only if free = 1)
} BlockHeader;

// Initialize the allocator
void free_list_init(void *memory, size_t size);

// Allocate memory from the arena
void *free_list_alloc(size_t size);

// Free memory from the arena
void free_list_free(void *ptr);

// (Optional) Combine adjacent free blocks
void free_list_coalesce();

#endif
