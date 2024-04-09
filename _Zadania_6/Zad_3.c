#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

int subtract(int a, int b) {
    return a - b;
}

int main() {
    int (*operation)(int, int);

    int num1, num2, choice;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    printf("Choose: 1Add, 2.Multiply, 3.Subtract: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            operation = add;
            break;
        case 2:
            operation = multiply;
            break;
        case 3:
            operation = subtract;
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }

    int result = operation(num1, num2);
    printf("Result: %d\n", result);

    return 0;
}