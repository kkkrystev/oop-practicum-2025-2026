#include <iostream>
#include <fstream>

namespace constants {
	const int BUFFER_SIZE = 1024;
}

void printFirstNLines(const char* filename, int N) {
    if (!filename) {
        std::cout << "Filename cannot be nullptr";
        return;
    }

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Cannot open file\n";
        return;
    }

    char line[constants::BUFFER_SIZE];
    int count = 0;
    while (count < N && file.getline(line, constants::BUFFER_SIZE)) {
        std::cout << line << '\n';
        count++;
    }

    file.close();
}