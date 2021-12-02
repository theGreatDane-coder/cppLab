#pragma once

#include <iostream>
#include <string>

using namespace std;

class Song {
private:
    string title;
    string band;

public:
    Song() {
    }
    
    Song(string title, string band) : title(title), band(band) {
    }

    void play() {
        cout << "Playing " << title << " of band " << band << endl;
    }

    string getTitle() {
        return title;
    }

    string getBand() {
        return band;
    }

    void print() {
        cout << "Song:" << title << " of band " << band << endl;
    }

    bool equals(const Song &other) const {
        if (this->band == other.band && this->title == other.title) {
            return true;
        } else {
            return false;
        }
    }

    bool operator==(const Song &other) const {
        if (this->band == other.band && this->title == other.title) {
            return true;
        } else {
            return false;
        }
    }

    friend ostream &operator<<(ostream &left, const Song &other);
};

ostream &operator<<(ostream &left, const Song &other) {
    left << "Song:" << other.title << " of band " << other.band << endl;
    return left;
}

class MediaPlayerTraits {
public:
    virtual void enqueue(Song song) = 0; // add to the end (append)

    virtual void remove(Song song) = 0; // remove a song from any place

    virtual void print() = 0;

    virtual void searchForTitle(string title) = 0;

    virtual void searchForBand(string band) = 0;

    virtual void play() = 0;

    virtual void first() = 0; // go to first song

    virtual void next() = 0; // go to next song

    virtual void previous() = 0; // go to previous song

    virtual void last() = 0; // go to last song

    virtual Song *getCurrentElement() = 0; // get current song
};
