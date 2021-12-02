#pragma once

#include <iostream>
#include <iterator>
#include <list>
#include <map>

#include "MediaPlayerTraits.h"

using namespace std;

class MediaPlayer : public MediaPlayerTraits {
private:
    list<Song> media;
    list<Song>::iterator current;

public:
    MediaPlayer() {
        current = media.begin();
    }

    virtual ~MediaPlayer() {
    }

    virtual void enqueue(Song song) {
        media.push_back(song);
    }

    virtual void remove(Song song) {
        for (list<Song>::iterator it = media.begin(); it != media.end(); ++it) {
            if (*it == song) {
                media.erase(it);
            }
        }
    }
    virtual void print() {
        for (list<Song>::iterator it = media.begin(); it != media.end(); ++it) {
            cout << *it;
        }
    }

    virtual void searchForTitle(string title) {
        for (list<Song>::iterator it = media.begin(); it != media.end(); ++it) {
            if (it->getTitle() == title) {
                it->print();
            }
        }
    }

    virtual void searchForBand(string band) {
        for (list<Song>::iterator it = media.begin(); it != media.end(); ++it) {
            if (it->getBand() == band) {
                it->print();
            }
        }
    }

    virtual void play() {
        if (media.size() == 0) {
            return;
        }

        current->play();
    }

    virtual void first() {
        if (media.size() == 0) {
            return;
        }

        current = media.begin();
    }

    virtual void next() {
        if (media.size() == 0) {
            return;
        }

        if (current != media.end()) {
            ++current;
        }
        play();
    }

    virtual void previous() {
        if (media.size() == 0) {
            return;
        }

        if (current != media.begin()) {
            --current;
        }
        play();
    }

    virtual void last() {
        if (media.size() == 0) {
            return;
        }

        current = media.end();
        --current;

        play();
    }

    virtual Song *getCurrentElement() {
        return &(*current);
    }
};