#include <stdio.h>
#include <stdlib.h>

void print_pascal_triangle(int n) {
    int **triangle = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        triangle[i] = (int *)malloc((i+1) * sizeof(int));
        triangle[i][0] = 1;
        triangle[i][i] = 1;
        for (int j = 1; j < i; j++) {
            triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", triangle[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        free(triangle[i]);
    }
    free(triangle);
}

int main() {
    print_pascal_triangle(10);
    return 0;
}