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
    unsigned int pos = 0;

public:
    MediaPlayer() {
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
        list<Song>::iterator it = media.begin();
        advance(it, pos);
        it->play();
    }

    virtual void first() {
        if (media.size() == 0) {
            return;
        }

        pos = 0;
        play();
    }

    virtual void next() {
        if (media.size() == 0) {
            return;
        }

        if (pos + 1 > media.size()) {
            pos = 0;
        } else {
            pos++;
        }
        play();
    }

    virtual void previous() {
        if (media.size() == 0) {
            return;
        }

        if (pos > 0) {
            pos--;
        }
        play();
    }

    virtual void last() {
        if (media.size() == 0) {
            return;
        }

        pos = media.size() - 1;
        play();
    }

    virtual Song *getCurrentElement() {
        list<Song>::iterator it = media.begin();
        advance(it, pos);
        return &(*it);
    }
};