#include <stdlib.h>

// We need to provide old_size manually, because standard library have implementation-dependend allocated block size tracking
void* realloc(void* ptr, size_t old_size, size_t new_size) {
    // Exceptional invariants
    if (ptr == NULL)
        return malloc(new_size);
    if (size == 0) {
        free(ptr);
        return NULL;
    }

    // Operate with both parts as arrays of chars
    // Assuming, that char is 1 byte
    char* old = (char*) ptr;
    char* new = (char*) malloc(new_size);

    for (int i = 0; i < old_size && i < new_size; i++)
        new[i] = old[i];

    free(ptr);
    return (void*) new;
}
    
