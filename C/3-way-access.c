
#include <stdio.h>

int main() {
    int arr[] = {5, 10, 15, 20, 25};

    // 1. Subscript notation
    printf("Using subscript: %d\n", arr[2]);

    // 2. Pointer with base address
    printf("Using pointer base address: %d\n", *(arr + 2));

    // 3. Offset pointer
    int *ptr = arr + 2;
    printf("Using offset pointer: %d\n", *ptr);

    return 0;
}
