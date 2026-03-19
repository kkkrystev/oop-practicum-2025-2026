#include <iostream>
#include <fstream>

namespace constants {
    const int MAX_WORD_LEN = 256;
}

void printLongestWord(const char* filename) {
    if (!filename) {
        std::cout << "Filename cannot be nullptr";
        return;
    }

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Cannot open file\n";
        return;
    }

    char word[constants::MAX_WORD_LEN];
    char longest[constants::MAX_WORD_LEN] = "";
    while (file >> word) {
        if (strlen(word) > strlen(longest)) {
            strcpy_s(longest, constants::MAX_WORD_LEN, word);
        }
    }

    std::cout << "Longest word: " << longest << "\n";
    file.close();
}