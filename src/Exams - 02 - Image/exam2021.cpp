#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <stdint.h>

#include "Image.h"
#include "codec.h"
#include "ppm.h"

#define RAND0TO255 ((unsigned char)floorf(255.5f * rand() / (float)RAND_MAX))

//------------------- Unit Tests declaration ----------------------------
void Test1(unsigned long seed);
void Test2(unsigned long seed);
void Test3(unsigned long seed);

//-------------------- main function ------------------------------------
int main(int argc, char** argv) {
    unsigned long seed = 1234; //

    Test1(seed);
    Test2(seed);
    Test3(seed);

    return 0;
}

//-------------------- Unit tests definitions ---------------------------
void Test1(unsigned long seed) {
    std::cout << "TEST 1: Basic funcionality.\n";
    std::cout << "---------------------------\n";

    srand(seed);

    graphics::Image im1; // To be implemented

    std::cout << "Checking default ctor...                       "
              << "[PASS]"
              << "\n";

    const int dim = 256;

    graphics::Image im2(dim, dim); // To be implemented

    unsigned char* memory = (reinterpret_cast<unsigned char**>(&im2))[0];
    memory[3 * dim * dim - 1] ^= '$';
    memory[3 * dim * dim - 1] ^= '$';
    std::cout << "Checking custom ctor...                        "
              << "[PASS]"
              << "\n";

    int pixel = rand() % (256 * 256);
    unsigned char rgb[3] = {RAND0TO255, RAND0TO255, RAND0TO255};

    unsigned char* newpixel = im2(pixel % dim, pixel / dim); // To be implemented

    newpixel[0] = rgb[0];
    newpixel[1] = rgb[1];
    newpixel[2] = rgb[2];

    im1 = im2; // To be implemented

    std::cout << "Checking operator() and operator = ...         ";
    bool resOK = true;
    for (int i = 0; i < 3 * dim * dim; i++) {
        if (im1(0, 0)[i] != im2(0, 0)[i]) {
            resOK = false;
            break;
        }
    }
    std::cout << (resOK ? "[PASS]" : "[FAIL]") << "\n";

    std::cout << "Checking operator == ...                       ";

    bool identical = (im1 == im2); // To be implemented

    std::cout << (identical ? "[PASS]" : "[FAIL]") << "\n";

    std::cout << "Checking copy ctor / dtor ...                  ";

    graphics::Image* im3 = new graphics::Image(im2); // To be implemented
    if ((*im3)(0, 0) == im2(0, 0)) {
        std::cout << "[FAIL]: Shallow copy attempted. Use DEEP data buffer copy.\n";
    } else {
        identical = (im2 == *im3);
        std::cout << (identical ? "[PASS]" : "[FAIL]: image content not identical.") << "\n";
    }
    delete im3; // To be implemented

    std::cout << "\n";
}

void Test2(unsigned long seed) {
    std::cout << "TEST 2: Load / save operations.\n";
    std::cout << "-------------------------------\n";

    srand(seed);

    graphics::Image im1;

    std::cout << "Checking load ...                              ";

    bool loadOK = im1.load("input.ppm"); // To be implemented

    int w = 0, h = 0;
    unsigned char* imbuf = graphics::ReadPPM("input.ppm", &w, &h);
    if (!imbuf)
        std::cout << "[FAIL] : could not find the input file.";
    else if (imbuf && (!loadOK || !im1(0, 0)))
        std::cout << "[FAIL].";
    else {
        bool resOK = true;
        for (int i = 0; i < 3 * w * h; i++) {
            if (im1(0, 0)[i] != imbuf[i]) {
                resOK = false;
                break;
            }
        }
        std::cout << (resOK ? "[PASS]" : "[FAIL].");
    }
    std::cout << "\n";

    std::cout << "Checking getDimensions...                      ";

    std::pair<int, int> dims = im1.getDimensions(); // To be implemented

    std::cout << ((dims.first == w && dims.second == h) ? "[PASS]" : "[FAIL]") << "\n";

    std::cout << "Checking save...                               ";
    unsigned char* buffer = im1(0, 0);
    for (int i = 0; i < 3 * w * h; i++) {
        buffer[i] = (unsigned char)std::max<int>(0, (int)(buffer[i] * 0.5f));
    }

    im1.save("output.ppm"); // To be implemented

    int sw = 0, sh = 0;
    if (imbuf)
        delete[] imbuf;
    imbuf = graphics::ReadPPM("output.ppm", &sw, &sh);
    bool saveOK = imbuf && sw == w && sh == h;

    std::cout << (saveOK ? "[PASS]" : "[FAIL]") << "\n";

    std::cout << "\n";
}

void Test3(unsigned long seed) {
    std::cout << "TEST 3: Conversion functionality.\n";
    std::cout << "-------------------------------\n";

    std::cout << "Checking encryption/decryption pipeline...     ";

    graphics::Image im1;
    bool loadOK = im1.load("input.ppm");

    if (!loadOK) {
        std::cout << "[FAIL] : could not find the input file.";
    } else {
        std::pair<int, int> dimensions = im1.getDimensions();
        CoDec codec(seed, dimensions.first * dimensions.second * 3);

        graphics::Image im2(dimensions.first, dimensions.second);

        im2 << codec.encrypt(im1); // To be implemented
        bool ok = im2.save("encrypted.ppm");
        if (ok) {
            im2 << codec.decrypt(im2);
            if (!(im1 == im2)) {
                std::cout << "[FAIL].\n";
            } else {
                std::cout << "[PASS].\n";
            }
        } else {
            std::cout << "[FAIL] : could not save encrypted file.\n";
        }
    }

    std::cout << "Testing move assignment operator...            ";
    graphics::Image im2 = im1;
    graphics::Image im3;
    unsigned char* data_base_addr1 = im1(0, 0);
    im3 = std::move(im1); // To be implemented
    if ((im1 == im3) || !(im2 == im3) || im3(0, 0) != data_base_addr1) {
        std::cout << "[FAIL]: Implement move assignment by \"stealing\" image resources, not copying them.\n";
    } else {
        std::cout << "[PASS].\n";
    }
}
