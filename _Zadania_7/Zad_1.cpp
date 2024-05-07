#include <iostream>
#include <fstream>
#include <string>
#include <array>

using namespace std;

class WordToDigitConverter {
public:
    pair<int, int> convert(const string& word) const {
        static const array<string, 10> numbers = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        for (int i = 0; i < 10; i++) {
            if (word.compare(0, numbers[i].size(), numbers[i]) == 0) {
                return {i, static_cast<int>(numbers[i].size())};
            }
        }
        return {-1, 0};
    }
};

int main() {
    ifstream input("C:\\Users\\kamil\\CLionProjects\\C_Zadania\\_Zadania_7\\files\\input.txt");
    ofstream output("C:\\Users\\kamil\\CLionProjects\\C_Zadania\\_Zadania_7\\files\\result.txt");
    string line;
    WordToDigitConverter converter;

    while (getline(input, line)) {
        int firstDigit = -1, lastDigit = -1;

        for (size_t i = 0; i < line.size(); i++) {
            if (line[i] >= '0' && line[i] <= '9') {
                if (firstDigit == -1) firstDigit = line[i] - '0';
                lastDigit = line[i] - '0';
            } else if (line[i] >= 'a' && line[i] <= 'z') {
                auto result = converter.convert(line.substr(i));
                if (result.first != -1) {
                    if (firstDigit == -1) firstDigit = result.first;
                    lastDigit = result.first;
                    i += result.second - 1;
                }
            }
        }

        if (firstDigit != -1 && lastDigit != -1) {
            output << firstDigit << lastDigit << "\n";
        }
    }

    return 0;
}