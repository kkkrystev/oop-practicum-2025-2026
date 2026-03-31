#pragma once

#include "Song.h"

class MusicPlayer {
private:
    Song* songs;
    int capacity;
    int count;

    void free();
    void copyFrom(const MusicPlayer& other);

public:
    MusicPlayer();
    MusicPlayer(int capacity);

    MusicPlayer(const MusicPlayer& other);
    MusicPlayer& operator=(const MusicPlayer& other);

    ~MusicPlayer();

    bool addSong(const Song& song);
    bool removeSong(int index);

    const Song& getLongestSong() const;
    int totalDuration() const;
};
