#include "Note.h"
#include <iostream>
#include <cstring>

#pragma warning(disable : 4996)

unsigned Note::idGenerator = 1;

void Note::setString(char* dest, const char* src)
{
    delete[] dest;

    if (!src)
    {
        dest = new char[1];
        dest[0] = '\0';
        return;
    }

    dest = new char[strlen(src) + 1];
    strcpy(dest, src);
}

void Note::copyFrom(const Note& other)
{
    if (!other.title)
    {
        title = new char[1];
        title[0] = '\0';
    }
    else
    {
        title = new char[strlen(other.title) + 1];
        strcpy(title, other.title);
    }

    if (!other.content)
    {
        content = new char[1];
        content[0] = '\0';
    }
    else
    {
        content = new char[strlen(other.content) + 1];
        strcpy(content, other.content);
    }
}

void Note::moveFrom(Note&& other)
{
    id = other.id;
    title = other.title;
    content = other.content;

    other.title = nullptr;
    other.content = nullptr;
    other.id = 0;
}

void Note::free()
{
    delete[] title;
    delete[] content;

    title = nullptr;
    content = nullptr;
    id = 0;
}

Note::Note()
{
    id = idGenerator++;

    title = new char[1];
    title[0] = '\0';

    content = new char[1];
    content[0] = '\0';
}

Note::Note(const char* title, const char* content)
{
    id = idGenerator++;

    if (!title)
    {
        this->title = new char[1];
        this->title[0] = '\0';
    }
    else
    {
        this->title = new char[strlen(title) + 1];
        strcpy(this->title, title);
    }

    if (!content)
    {
        this->content = new char[1];
        this->content[0] = '\0';
    }
    else
    {
        this->content = new char[strlen(content) + 1];
        strcpy(this->content, content);
    }
}

Note::Note(const Note& other)
{
    copyFrom(other);
}

Note& Note::operator=(const Note& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

Note::Note(Note&& other) noexcept
{
    moveFrom(std::move(other));
}

Note& Note::operator=(Note&& other) noexcept
{
    if (this != &other)
    {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

Note::~Note()
{
    free();
}

void Note::setTitle(const char* title)
{
    setString(this->title, title);
}

void Note::setContent(const char* content)
{
    setString(this->content, content);
}

const char* Note::getTitle() const
{
    return title;
}

const char* Note::getContent() const
{
    return content;
}

unsigned Note::getId() const
{
    return id;
}

void Note::print() const
{
    std::cout << "Id: " << id << '\n';
    std::cout << "Title: " << title << '\n';
    std::cout << "Content: " << content << '\n';
}

void Note::saveToFile(std::ofstream& ofs) const
{
    ofs.write((const char*)&id, sizeof(id));

    size_t titleLen = strlen(title);
    ofs.write((const char*)&titleLen, sizeof(titleLen));
    ofs.write(title, titleLen + 1);

    size_t contentLen = strlen(content);
    ofs.write((const char*)&contentLen, sizeof(contentLen));
    ofs.write(content, contentLen + 1);
}

void Note::readFromFile(std::ifstream& ifs)
{
    free();

    ifs.read((char*)&id, sizeof(id));

    size_t titleLen = 0;
    ifs.read((char*)&titleLen, sizeof(titleLen));
    title = new char[titleLen + 1];
    ifs.read(title, titleLen + 1);

    size_t contentLen = 0;
    ifs.read((char*)&contentLen, sizeof(contentLen));
    content = new char[contentLen + 1];
    ifs.read(content, contentLen + 1);

    if (id >= idGenerator)
        idGenerator = id + 1;
}