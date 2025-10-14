#pragma once
#include <string>
#include <vector>

using namespace std;

class PPMImage {
private:
    int width, height, maxColor;
    unsigned char* data; // 3 * width * height

public:
    PPMImage();
    ~PPMImage();

    bool loadFromFile(const string& filename);   // ASCII (P3)
    bool saveToFile(const string& filename) const; // ASCII (P3)

    int getWidth() const { return width; }
    int getHeight() const { return height; }
    const unsigned char* getData() const { return data; }
};