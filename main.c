#include <stdio.h>
#include <string.h>

int wordToDigit(char *word) {
    if (strcmp(word, "zero") == 0) return 0;
    if (strcmp(word, "one") == 0) return 1;
    if (strcmp(word, "two") == 0) return 2;
    if (strcmp(word, "three") == 0) return 3;
    if (strcmp(word, "four") == 0) return 4;
    if (strcmp(word, "five") == 0) return 5;
    if (strcmp(word, "six") == 0) return 6;
    if (strcmp(word, "seven") == 0) return 7;
    if (strcmp(word, "eight") == 0) return 8;
    if (strcmp(word, "nine") == 0) return 9;
    return -1;
}

int main() {
    FILE *input = fopen("C:\\Users\\kamil\\CLionProjects\\demo2\\files\\input.txt", "r");
    FILE *output = fopen("C:\\Users\\kamil\\CLionProjects\\demo2\\files\\result.txt", "w");

    char line[256];
    while (fgets(line, sizeof(line), input)) {
        char word[256] = "";
        int firstDigit = -1, lastDigit = -1;

        for (int i = 0; line[i] != '\0'; i++) {
            if (line[i] >= '0' && line[i] <= '9') {
                if (firstDigit == -1) firstDigit = line[i] - '0';
                lastDigit = line[i] - '0';
                word[0] = '\0'; // Resetuj słowo
            } else if (line[i] >= 'a' && line[i] <= 'z') {
                strncat(word, &line[i], 1); // Dodaj znak do słowa
                int digit = wordToDigit(word);
                if (digit != -1) {
                    if (firstDigit == -1) firstDigit = digit;
                    lastDigit = digit;
                    word[0] = '\0'; // Resetuj słowo
                }
            }
        }

        if (firstDigit != -1 && lastDigit != -1) {
            fprintf(output, "%d%d\n", firstDigit, lastDigit); // Zapisz do pliku wynikowego
        }
    }

    fclose(input);
    fclose(output);

    return 0;
}