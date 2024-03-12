#include <stdio.h>

int binary_recursion_search(int* array, int left, int right, int element) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        if (array[mid] == element)
            return mid;

        if (array[mid] > element)
            return binary_recursion_search(array, left, mid - 1, element);

        return binary_recursion_search(array, mid + 1, right, element);
    }

    return -1;
}

int main() {

    int array[] = {2, 3, 4, 10, 40, 50, 60, 70, 80, 90, 100};
    int element = 50;
    printf("Index of value %d is %d\n", element, binary_recursion_search(array, 0, 10, element));
    return 0;
}