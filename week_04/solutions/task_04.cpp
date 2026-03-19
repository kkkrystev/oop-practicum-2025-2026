#include <iostream>
#include <fstream>

bool copyFile(const char* source, const char* dest) {
    if (!source || !dest)
        return false;

    if (strcmp(source, dest) == 0)
        return false;

    std::ifstream in(source, std::ios::binary);
    if (!in.is_open())
        return false;

    std::ofstream out(dest, std::ios::binary | std::ios::app);
    if (!out.is_open())
        return false;

    char ch;
    while (in.get(ch)) {
        out.put(ch);
        if (!out)
            return false;
    }

    return true;
}