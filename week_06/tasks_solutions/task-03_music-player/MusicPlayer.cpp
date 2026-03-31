#include "MusicPlayer.h"

void MusicPlayer::free() {
    delete[] songs;
    songs = nullptr;

    count = 0;
    capacity = 0;
}

void MusicPlayer::copyFrom(const MusicPlayer& other) {
    capacity = other.capacity;
    count = other.count;

    songs = new Song[capacity];

    for (int i = 0; i < count; i++) {
        songs[i] = other.songs[i];
    }
}

MusicPlayer::MusicPlayer()
    : songs(new Song[50]),
    capacity(50),
    count(0)
{
}

MusicPlayer::MusicPlayer(int capacity)
    : songs(new Song[capacity]),
    capacity(capacity),
    count(0)
{
}

MusicPlayer::MusicPlayer(const MusicPlayer& other)
    : songs(nullptr), capacity(0), count(0)
{
    copyFrom(other);
}

MusicPlayer& MusicPlayer::operator=(const MusicPlayer& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

MusicPlayer::~MusicPlayer() {
    free();
}

bool MusicPlayer::addSong(const Song& song) {
    if (count >= capacity) 
        return false;

    songs[count] = song;
    count++;

    return true;
}

bool MusicPlayer::removeSong(int index) {
    if (index < 0 || index >= count) 
        return false;

    for (int i = index; i < count - 1; i++) {
        songs[i] = songs[i + 1];
    }

    count--;
    return true;
}

const Song& MusicPlayer::getLongestSong() const {
    if (count == 0) return Song();

    int maxIdx = 0;

    for (int i = 1; i < count; i++) {
        if (songs[i].getDuration() > songs[maxIdx].getDuration()) {
            maxIdx = i;
        }
    }

    return songs[maxIdx];
}

int MusicPlayer::totalDuration() const {
    int sum = 0;

    for (int i = 0; i < count; i++) {
        sum += songs[i].getDuration();
    }

    return sum;
}