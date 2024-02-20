#include <stdio.h>

int main() {
    int cont = 1;
    int p1Wins = 0;
    int p2Wins = 0;
    while (cont == 1) {
        int inp = 0;
        printf("Player 1 move: \n1. Rock\n2. Paper\n3. Scissors\n");
        int choice1 = 0;
        scanf("choice1: %i", inp);
        printf("Player 2 move: \n1. Rock\n2. Paper\n3. Scissors\n");
        int choice2 = 0;
        scanf("choice2: %i", choice2);

        if (choice1 == 1 && choice2 == 2) {
            printf("Player 2 wins\n");
            p2Wins++;
        }
        else if (choice1 == 2 && choice2 == 3) {
            printf("Player 2 wins\n");
            p2Wins++;
        }
        else if (choice1 == 3 && choice2 == 1) {
            printf("Player 2 wins\n");
            p2Wins++;
        }
        else if (choice1 == 1 && choice2 == 3) {
            printf("Player 1 wins\n");
            p1Wins++;
        }
        else if (choice1 == 2 && choice2 == 1) {
            printf("Player 1 wins\n");
            p1Wins++;
        }
        else if (choice1 == 3 && choice2 == 2) {
            printf("Player 1 wins\n");
            p1Wins++;
        }
        else {
            printf("Tie\n");
        }



    }


    return 0;
}

