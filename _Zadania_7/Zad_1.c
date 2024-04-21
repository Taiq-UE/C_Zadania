#include <stdio.h>
#include <string.h>

typedef struct {
    int digit;
    int length;
} WordToDigitResult;

WordToDigitResult wordToDigit(char *word) {
    char *numbers[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    for (int i = 0; i < 10; i++) {
        if (strncmp(word, numbers[i], strlen(numbers[i])) == 0) {
            return (WordToDigitResult){.digit = i, .length = strlen(numbers[i])};
        }
    }
    return (WordToDigitResult){.digit = -1, .length = 0};
}

int main() {
    //nie działają ścieżki względne
    FILE *input = fopen("C:\\Users\\kamil\\CLionProjects\\C_Zadania\\_Zadania_7\\files\\input.txt", "r");
    FILE *output = fopen("C:\\Users\\kamil\\CLionProjects\\C_Zadania\\_Zadania_7\\files\\result.txt", "w");

    char line[256];
    while (fgets(line, sizeof(line), input)) {
        int firstDigit = -1, lastDigit = -1;

        for (int i = 0; line[i] != '\0'; i++) {
            if (line[i] >= '0' && line[i] <= '9') {
                if (firstDigit == -1) firstDigit = line[i] - '0';
                lastDigit = line[i] - '0';
            } else if (line[i] >= 'a' && line[i] <= 'z') {
                WordToDigitResult result = wordToDigit(&line[i]);
                if (result.digit != -1) {
                    if (firstDigit == -1) firstDigit = result.digit;
                    lastDigit = result.digit;
                    i += result.length - 1;
                }
            }
        }

        if (firstDigit != -1 && lastDigit != -1) {
            fprintf(output, "%d%d\n", firstDigit, lastDigit);
        }
    }

    fclose(input);
    fclose(output);

    return 0;
}