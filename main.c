#include <stdio.h>
#include <math.h>

struct Point {
    int x;
    int y;
};

struct Rectangle {
    struct Point *x1;
    struct Point *y1;
};

void addOne(struct Point *p) {
    (*p).x++;
    (*p).y++;
}

void rectCalc(struct Rectangle *r) {
    float width = abs((*r).x1->x - (*r).y1->x);
    float height = abs((*r).x1->y - (*r).y1->y);

    float area = width * height;
    float perimeter = 2 * (width + height);
    printf("Area: %f\n", area);
    printf("Perimeter: %f\n", perimeter);
}

int main() {
    struct Point x = {-1, -1};
    printf("Before: (%d, %d)\n", x.x, x.y);
    struct Point *pointer = &x;
    addOne(pointer);
    printf("After: (%d, %d)\n", x.x, x.y);

    struct Point y = {1, 1};

    struct Rectangle r = {pointer, &y};

    rectCalc(&r);

    return 0;
}

