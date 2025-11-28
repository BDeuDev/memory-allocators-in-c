#include "bump.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    size_t arena_size = 1024;

    void *arena = malloc(arena_size);
    bump_init(arena, arena_size);

    int *a = bump_alloc(sizeof(int));
    *a = 42;

    char *b = bump_alloc(4);
    b[0] = 'H';
    b[1] = 'i';
    b[2] = '!';
    b[3] = '\0';

    printf("a = %d\n", *a);
    printf("b = %s\n", b);

    bump_reset();
    free(arena);
    return 0;
}
