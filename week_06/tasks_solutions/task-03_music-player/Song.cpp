#include "Song.h"
#include <cstring>

void Song::free() {
    delete[] title;
    title = nullptr;

    delete[] artist;
    artist = nullptr;

    duration = 0;
    genre = 0;
}

void Song::copyFrom(const Song& other)
{
    duration = other.duration;
    genre = other.genre;

    title = new char[std::strlen(other.title) + 1];
    strcpy_s(title, std::strlen(other.title) + 1, other.title);

    artist = new char[std::strlen(other.artist) + 1];
    strcpy_s(artist, std::strlen(other.artist) + 1, other.artist);
}

Song::Song()
    : title(new char[1] {'\0'}),
    artist(new char[1] {'\0'}),
    duration(0),
    genre(0)
{}

Song::Song(const char* t, const char* a, int d, int g)
    : title(nullptr), artist(nullptr), duration(d), genre(g)
{
    if (!t) {
        title = new char[1] {'\0'};
    }
    else {
        title = new char[std::strlen(t) + 1];
        strcpy_s(title, std::strlen(t) + 1, t);
    }

    if (!a) {
        artist = new char[1] {'\0'};
    }
    else {
        artist = new char[std::strlen(a) + 1];
        strcpy_s(artist, std::strlen(a) + 1, a);
    }
}

Song::Song(const Song& other)
    : title(nullptr), artist(nullptr)
{
    copyFrom(other);
}

Song& Song::operator=(const Song& other) 
{
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

Song::~Song() 
{
    free();
}


const char* Song::getTitle() const
{
    return title;
}

const char* Song::getArtist() const 
{ 
    return artist; 
}

int Song::getDuration() const 
{ 
    return duration; 
}

int Song::getGenre() const 
{ 
    return genre; 
}