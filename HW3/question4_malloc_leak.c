#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = malloc(100 * sizeof(int)); // To allocate memory for 100 integers on the heap.
    *ptr = 3; // Store a value in the allocated memory
    return 0;
}