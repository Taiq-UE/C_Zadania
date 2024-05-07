#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#define MAX_ROUNDS 10
#define MAX_RED 12
#define MAX_GREEN 13
#define MAX_BLUE 14

using namespace std;

int main() {
    ifstream input("C:\\Users\\kamil\\CLionProjects\\C_Zadania\\_Zadania_7\\files\\input2.txt");
    if (!input.is_open()) {
        cout << "Cant open file\n";
        return 1;
    }

    string line;
    int sum_game_ids = 0;
    int sum_mins_power = 0;
    while (getline(input, line)) {
        int game_id;
        istringstream iss(line);
        string game;
        iss >> game >> game_id;
        cout << "\n\nGame ID: " << game_id << "\n";

        size_t colon_position = line.find(':');
        if (colon_position != string::npos) {
            string line_after_colon = line.substr(colon_position + 2);

            vector<string> rounds;
            istringstream ss(line_after_colon);
            string round;
            while (getline(ss, round, ';') && rounds.size() < MAX_ROUNDS) {
                rounds.push_back(round);
            }

            int game_valid = 1;
            int min_red = 0, min_green = 0, min_blue = 0;
            for (int i = 0; i < rounds.size(); i++) {
                cout << "Round " << i + 1 << ": " << rounds[i] << "\n";

                int red = 0, green = 0, blue = 0;
                istringstream ss(rounds[i]);
                string color;
                while (getline(ss, color, ',')) {
                    int value;
                    string color_name;
                    istringstream colorStream(color);
                    colorStream >> value >> color_name;
                    if (color_name == "red") {
                        red += value;
                        if (red > MAX_RED) {
                            game_valid = 0;
                            cout << "Game " << game_id << " exceeded red limit in round " << i + 1 << "\n";
                        }
                        if (red > min_red) {
                            min_red = red;
                        }
                    } else if (color_name == "green") {
                        green += value;
                        if (green > MAX_GREEN) {
                            game_valid = 0;
                            cout << "Game " << game_id << " exceeded green limit in round " << i + 1 << "\n";
                        }
                        if (green > min_green) {
                            min_green = green;
                        }
                    } else if (color_name == "blue") {
                        blue += value;
                        if (blue > MAX_BLUE) {
                            game_valid = 0;
                            cout << "Game " << game_id << " exceeded blue limit in round " << i + 1 << "\n";
                        }
                        if (blue > min_blue) {
                            min_blue = blue;
                        }
                    }
                }
            }

            if (game_valid) {
                sum_game_ids += game_id;
            }

            cout << "Min number of reds: " << min_red << ", Min number of greens: " << min_green << ", Min number of blues: " << min_blue << "\n";
            sum_mins_power += min_red * min_green * min_blue;
            cout << "Mins power: " << min_red * min_green * min_blue << "\n";
        }
    }

    cout << "\n\nSum of mins power: " << sum_mins_power << "\n";
    cout << "Sum of IDs: " << sum_game_ids << "\n";
    return 0;
}