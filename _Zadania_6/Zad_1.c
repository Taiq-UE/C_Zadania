#include <stdio.h>

union Data {
    int integer;
    float floating;
    char character;
};

int main() {
    union Data data;

    data.integer = 21;
    printf("data.integer: %d\n", data.integer);

    data.floating = 3.7;
    printf("data.floating: %f\n", data.floating);

    data.character = 'A';
    printf("data.character: %c\n", data.character);

    return 0;
}