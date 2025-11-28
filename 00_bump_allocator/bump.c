#include "bump.h"
#include <stdint.h>

static uint8_t *bump_base = NULL;
static size_t bump_capacity = 0;
static size_t bump_offset = 0;

void bump_init(void *memory, size_t size)
{
    bump_base = (uint8_t *)memory;
    bump_capacity = size;
    bump_offset = 0;
}

void *bump_alloc(size_t size)
{
    if (bump_offset + size > bump_capacity)
    {
        return NULL;
    }

    void *ptr = bump_base + bump_offset;

    bump_offset += size;

    return ptr;
}

void bump_reset()
{
    bump_offset = 0;
}
