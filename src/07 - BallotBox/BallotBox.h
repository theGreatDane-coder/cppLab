#pragma once

#include <map>

#include "BallotBoxTraits.h"

using namespace std;

template <typename T>
class BallotBox : public BallotBoxTraits<T> {
private:
    map<T, int> data;
public:
    virtual void place(T item) {
        typename map<T, int>::iterator iter = data.find(item);
        if (iter == data.end()) {
            pair<T, int> p(item, 1);
            data.insert(p);
            //data.insert(pair<T, int>(item, 1));
        }
        else {
            iter->second = iter->second++;
        }
    }

    virtual void place(const vector<T>& input) {
        for (typename vector<T>::const_iterator veciter = input.begin(); veciter != input.end(); ++veciter) {
            place(*veciter);
        }

        //or
        /*for (typename vector<T>::const_iterator veciter = input.begin(); veciter != input.end(); ++veciter) {
            typename map<T, int>::iterator mapiter = data.find(*veciter);
            if (mapiter == data.end()) {
                pair<T, int> p(*veciter, 1);
                data.insert(p);
            }
            else {
                mapiter->second = mapiter->second++;
            }
        }*/
    }

    virtual void operator+=(T item) {
        place(item);

        //or 
        /*typename map<T, int>::iterator iter = data.find(item);
        if (iter == data.end()) {
            pair<T, int> p(item, 1);
            data.insert(p);
        }
        else {
            iter->second = iter->second++;
        }*/
    }

    virtual void clear() {
        data.clear();
    }

    virtual int getFrequency(T item) {
        typename map<T, int>::iterator iter = data.find(item);
        if (iter == data.end()) {
            return 0;
        }
        else {
            return iter->second;
        }
    }
	

};