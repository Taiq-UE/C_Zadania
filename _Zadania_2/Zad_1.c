#include <stdio.h>

int main() {
    int x = 5;
    int *pointer = &x;
    *pointer = 10;
    printf("%d\n", x);
    printf("%d\n", *pointer);
    return 0;
}

