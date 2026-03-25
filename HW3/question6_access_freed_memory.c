#include <stdio.h>
#include <stdlib.h>

int main() {

    int *data = malloc(100 * sizeof(int)); // To allocate memory for 100 integers.

    data[10] = 25;

    free(data); // Free the allocated memory.

    printf("Value: %d\n", data[10]); // Trying to access the memory after it has been freed.

    return 0;
}