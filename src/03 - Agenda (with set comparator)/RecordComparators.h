#include "Record.h"

class FirstnameComparator {
public:
    bool operator()(const Record &left, const Record &right) const {
        if (left.getFirstname() < right.getFirstname()) {
            return true;
        } else {
            return false;
        }
    }
};

class LastnameComparator {
public:
    bool operator()(const Record &left, const Record &right) const {
        if (left.getLastname() < right.getLastname()) {
            return true;
        } else {
            return false;
        }
    }
};

class PhoneComparator {
public:
    bool operator()(const Record &left, const Record &right) const {
        if (left.getPhone() < right.getPhone()) {
            return true;
        } else {
            return false;
        }
    }
};