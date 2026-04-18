#pragma once
#include <fstream>

class Note
{
private:
    unsigned id;
    char* title;
    char* content;

    static unsigned idGenerator;

    void copyFrom(const Note& other);
    void moveFrom(Note&& other);
    void free();

    void setString(char* dest, const char* src);

public:
    Note();
    Note(const char* title, const char* content);

    Note(const Note& other);
    Note& operator=(const Note& other);

    Note(Note&& other) noexcept;
    Note& operator=(Note&& other) noexcept;

    ~Note();

    void setTitle(const char* title);
    void setContent(const char* content);

    const char* getTitle() const;
    const char* getContent() const;
    unsigned getId() const;

    void print() const;

    void saveToFile(std::ofstream& ofs) const;
    void readFromFile(std::ifstream& ifs);
};