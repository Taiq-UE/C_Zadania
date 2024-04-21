#include <stdio.h>
#include <string.h>

#define MAX_ROUNDS 10
#define MAX_RED 12
#define MAX_GREEN 13
#define MAX_BLUE 14

int main() {
    //nie działają ścieżki względne
    FILE *input = fopen("C:\\Users\\kamil\\CLionProjects\\C_Zadania\\_Zadania_7\\files\\input2.txt", "r");
    if (input == NULL) {
        printf("Cant open file\n");
        return 1;
    }

    char line[256];
    int sum_game_ids = 0;
    int sum_mins_power = 0;
    while (fgets(line, sizeof(line), input)) {
        int game_id;
        sscanf(line, "Game %d:", &game_id);
        printf("\n\nGame ID: %d\n", game_id);

        char *colon_position = strchr(line, ':');
        if (colon_position != NULL) {
            char *line_after_colon = colon_position + 2;

            char *rounds[MAX_ROUNDS];
            int num_rounds = 0;

            char *round = strtok(line_after_colon, ";");
            while (round != NULL && num_rounds < MAX_ROUNDS) {
                rounds[num_rounds] = round;
                num_rounds++;

                round = strtok(NULL, ";");
            }

            int game_valid = 1;
            int min_red = 0, min_green = 0, min_blue = 0;
            for (int i = 0; i < num_rounds; i++) {
                printf("Round %d: %s\n", i + 1, rounds[i]);

                int red = 0, green = 0, blue = 0;
                char *color = strtok(rounds[i], ",");
                while (color != NULL) {
                    int value;
                    char color_name[6];
                    sscanf(color, " %d %s", &value, color_name);
                    if (strcmp(color_name, "red") == 0) {
                        red += value;
                        if (red > MAX_RED) {
                            game_valid = 0;
                            printf("Game %d exceeded red limit in round %d\n", game_id, i + 1);
                        }
                        if (red > min_red) {
                            min_red = red;
                        }
                    } else if (strcmp(color_name, "green") == 0) {
                        green += value;
                        if (green > MAX_GREEN) {
                            game_valid = 0;
                            printf("Game %d exceeded green limit in round %d\n", game_id, i + 1);
                        }
                        if (green > min_green) {
                            min_green = green;
                        }
                    } else if (strcmp(color_name, "blue") == 0) {
                        blue += value;
                        if (blue > MAX_BLUE) {
                            game_valid = 0;
                            printf("Game %d exceeded blue limit in round %d\n", game_id, i + 1);
                        }
                        if (blue > min_blue) {
                            min_blue = blue;
                        }
                    }
                    color = strtok(NULL, ",");
                }
            }

            if (game_valid) {
                sum_game_ids += game_id;
            }

            printf("Min number of reds: %d, Min number of greens: %d, Min number of blues: %d\n", min_red, min_green, min_blue);
            sum_mins_power += min_red * min_green * min_blue;
            printf("Mins power: %d\n", min_red * min_green * min_blue);
        }
    }

    fclose(input);
    printf("\n\nSum of mins power: %d\n", sum_mins_power);
    printf("Sum of IDs: %d\n", sum_game_ids);
    return 0;
}