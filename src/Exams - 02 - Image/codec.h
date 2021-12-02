#pragma once

#include <cstring>

//------------------- CoDec class required for Test3 --------------------
class CoDec {
    uint64_t key;
    size_t length;
    unsigned char* buffer;

public:
    CoDec(uint64_t key, size_t stream_length);
    ~CoDec();
    const unsigned char* const encrypt(unsigned char* stream);
    const unsigned char* const decrypt(unsigned char* stream);
};

//-------------------- CoDec class definition ---------------------------

CoDec::CoDec(uint64_t key, size_t stream_length)
    : key(key), length(stream_length), buffer(new unsigned char[stream_length]) {
    // fill msb s with lsb bits on the key
    key |= ~(key << 32);
}

const unsigned char* const CoDec::encrypt(unsigned char* input) {
    uint64_t local_key = key;
    int offset = 0;

    for (unsigned i = 0; i < length; i++) {
        offset = i / 509;
        buffer[i] = input[i] ^ ((unsigned char)(local_key & 0xff));
        local_key = (local_key << (i + offset) % 64) | (local_key >> (64 - (i + offset) % 64));
    }
    local_key = key;
    offset = 0;
    const int range = 97;
    unsigned char tmp[range];
    for (unsigned i = 0; i < length - 2 * range; i += 2 * range) {
        offset = i / 313;
        local_key = (local_key << (i + offset) % 64) | (local_key >> (64 - (i + offset) % 64));

        if (local_key & 127) {
            memcpy(tmp, buffer + i, range);
            memcpy(buffer + i, buffer + range + i, range);
            memcpy(buffer + range + i, tmp, range);
        }
    }

    return buffer;
}

const unsigned char* const CoDec::decrypt(unsigned char* input) {
    uint64_t local_key = key;
    int offset = 0;
    memcpy(buffer, input, length);
    const int range = 97;
    unsigned char tmp[range];
    for (unsigned i = 0; i < length - 2 * range; i += 2 * range) {
        offset = i / 313;
        local_key = (local_key << (i + offset) % 64) | (local_key >> (64 - (i + offset) % 64));

        if (local_key & 127) {
            memcpy(tmp, buffer + i, range);
            memcpy(buffer + i, buffer + range + i, range);
            memcpy(buffer + range + i, tmp, range);
        }
    }
    local_key = key;
    offset = 0;
    for (unsigned i = 0; i < length; i++) {
        offset = i / 509;
        buffer[i] = buffer[i] ^ ((unsigned char)(local_key & 0xff));
        local_key = (local_key << (i + offset) % 64) | (local_key >> (64 - (i + offset) % 64));
    }
    return buffer;
}

CoDec::~CoDec() {
    delete[] buffer;
}
