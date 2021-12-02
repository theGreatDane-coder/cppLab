#include "ImageStorageTraits.h"

#include <iostream>
#include <utility>

#include "ppm.h"

using namespace std;
namespace graphics {
    class Image : public ImageStorageTraits {
    private:
        // unsigned char* data = nullptr;
        // int width = 0;
        // int height = 0;
    public:
        // -------------------------------------------- Test 1
        Image() {
            width = 0;
            height = 0;
            data = nullptr;
        }

        Image(int width, int height) {
            if (width == 0 || height == 0) {
                width = 0;
                height = 0;
                data = nullptr;
            } else {
                this->width = width;
                this->height = height;
                this->data = new unsigned char[width * height * 3];
            }
        }

        Image(const Image& other) {
            this->width = other.width;
            this->height = other.height;
            this->data = new unsigned char[width * height * 3];

            for (int i = 0; i < width * height * 3; i++) {
                this->data[i] = other.data[i];
            }
        }

        ~Image() {
            if (data != nullptr) {
                delete[] data;
            }
        }

        unsigned char* operator()(int x, int y) {
            return pixel(x, y);
        }

        Image& operator=(const Image& other) {
            if (this == &other) {
                return *this;
            }

            if (data) {
                delete[] data;
            }

            this->width = other.width;
            this->height = other.height;
            this->data = new unsigned char[width * height * 3];

            for (int i = 0; i < width * height * 3; i++) {
                this->data[i] = other.data[i];
            }

            return *this;
        }

        bool operator==(const Image& other) const {
            if (width != other.width || height != other.height) {
                return false;
            }

            if (this == &other) {
                return true;
            }

            for (int i = 0; i < width * height * 3; i++) {
                if (data[i] != other.data[i]) {
                    return false;
                }
            }

            return true;
        }

        // -------------------------------------------- Test 2
        bool load(string filename) {
            data = graphics::ReadPPM(filename, &width, &height);

            if (data == nullptr) {
                return false;
            } else {
                return true;
            }
        }

        pair<int, int> getDimensions() const {
            pair<int, int> p;
            p.first = width;
            p.second = height;
            return p;
        }

        bool save(string filename) {
            bool result = graphics::WritePPM(data, width, height, filename);

            return result;
        }

        // -------------------------------------------- Test 3
        Image& operator<<(const unsigned char* data) {
            for (int i = 0; i < width * height * 3; i++) {
                this->data[i] = data[i];
            }

            return *this;
        }

        operator unsigned char*() {
            return data;
        }
    };
} // namespace graphics