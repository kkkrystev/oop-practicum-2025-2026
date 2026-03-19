#include <fstream>

namespace constants {
    const int BUFFER_SIZE = 1024;
}

int countFileLines(const char* filename) {
    if (!filename) return -1;

    std::ifstream file(filename);
    if (!file.is_open()) return -1;

    int lines = 0;
    char buffer[1024];

    while (file.getline(buffer, constants::BUFFER_SIZE)) {
        lines++;
    }

    return lines;
}