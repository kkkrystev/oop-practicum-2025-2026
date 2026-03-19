#include <iostream>
#include <fstream>
#include <cstring>

namespace constants {
    const int MAX_LINE_LEN = 1024;
}

int countEmptyLines(const char* filename) {
    std::ifstream file(filename);
    if (!file.is_open())
        return -1;

    int count = 0;
    bool isEmpty = true;
    char c;

    while (file.get(c)) {
        if (c == '\n') {
            // end of a line has been reached
            // if no non-whitespace symbols were found, count it
            if (isEmpty)
                count++;

            // reset state for the next line
            isEmpty = true;
        }
        else if (c != ' ' && c != '\t' && c != '\r') {
            // any non-whitespace character means the line is not empty
            isEmpty = false;
        }
    }

    // handle last line
    if (isEmpty)
        count++;

    return count;
}