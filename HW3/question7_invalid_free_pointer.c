#include <stdio.h>
#include <stdlib.h>

int main() {

    int *data = malloc(100 * sizeof(int)); // To allocate memory for 100 integers.

    if (data == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < 100; i++) {
        data[i] = i;
    }

    free(&data[50]); // Incorrectly free a pointer from the middle of the array.

    return 0;
}