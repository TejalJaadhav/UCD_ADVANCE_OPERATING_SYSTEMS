#include <stdio.h>
#include <stdlib.h>

int main() {
    int *data = malloc(100 * sizeof(int));  // To allocate memory for 100 integers.

    data[100] = 0;  // Attempt to write to index 100.

    free(data);     // Free allocated memory.
    return 0;
}