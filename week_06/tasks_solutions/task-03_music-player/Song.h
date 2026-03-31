#pragma once

class Song
{
    char* title;
    char* artist;
    int duration;
    int genre;

    void free();
    void copyFrom(const Song& other);

public:
    Song();
    Song(const char* title, const char* artist, int duration, int genre);

    Song(const Song& other);
    Song& operator=(const Song& other);

    ~Song();

    const char* getTitle() const;
    const char* getArtist() const;
    int getDuration() const;
    int getGenre() const;
};

