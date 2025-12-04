#include "free_list.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    size_t arena_size = 1024;
    void *arena = malloc(arena_size);

    free_list_init(arena, arena_size);

    printf("Allocating A...\n");
    int *a = free_list_alloc(sizeof(int));
    *a = 42;

    printf("Allocating B...\n");
    char *b = free_list_alloc(1);
    b[0] = 'H';
    b[1] = 'i';
    b[2] = '!';
    b[3] = 0;

    printf("A = %d\n", *a);
    printf("B = %s\n", b);

    printf("Freeing A...\n");
    free_list_free(a);

    printf("Freeing B...\n");
    free_list_free(b);

    void *c = free_list_alloc(10000);
    if (!c) {
       printf("Cannot Allocate C (10000 bytes)\n");    
       printf("ERROR!\n");
    } else {
       printf("Allocating C (10000 bytes)...\n");
       printf("OK!\n");
    }
    
    void *d = free_list_alloc(100);
    if(!d) {
       printf("Cannot Allocate D (100 bytes)...\n");
       printf("ERROR!\n");  
    } else {
       printf("Alocating D (100 bytes)...\n");
       printf("OK!\n");
    }


    free(arena);
    return 0;
}

