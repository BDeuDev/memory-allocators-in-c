#include "free_list.h"
#include <stdint.h>

static BlockHeader *free_list_head = NULL;

void free_list_init(void *memory, size_t size) {
    free_list_head = (BlockHeader *)memory;
    free_list_head->size = size - sizeof(BlockHeader);
    free_list_head->free = 1;
    free_list_head->next = NULL;
}

static void split_block(BlockHeader *block, size_t size) {
    if (block->size < size + sizeof(BlockHeader) + 1) {
        return;
    }

    uint8_t *block_start = (uint8_t *)block;

    BlockHeader *new_block = (BlockHeader *)(block_start + sizeof(BlockHeader) + size);

    new_block->size = block->size - size - sizeof(BlockHeader);
    new_block->free = 1;
    new_block->next = block->next;

    block->size = size;
    block->next = new_block;
}

void *free_list_alloc(size_t size) {
    BlockHeader *current = free_list_head;

    while (current) {
        if (current->free && current->size >= size) {
            split_block(current, size);

            current->free = 0;

            return (uint8_t *)current + sizeof(BlockHeader);
        }
        current = current->next;
    }

    return NULL;

}

void free_list_free(void *ptr) {
    if (!ptr) return;

    BlockHeader *block = (BlockHeader *)((uint8_t *)ptr - sizeof(BlockHeader)); block->free = 1; 
    free_list_coalesce();
}


void free_list_coalesce() {
    BlockHeader *current = free_list_head;

    while (current && current->next) {
        if (current->free && current->next->free) {
            current->size += sizeof(BlockHeader) + current->next->size;
            current->next = current->next->next;
        } else {
            current = current->next;
        }
    }
}
