#include "PPMImage.h"
#include <iostream>
using namespace std;
int main() {
    PPMImage image;
    if (image.loadFromFile("image.ppm")) {
        cout << "Image loaded: " << image.getWidth() << "x" << image.getHeight() << endl;
        image.saveToFile("copy.ppm");
        cout << "Image saved as copy.ppm" << endl;
    } else {
        cout << "Failed to load image." << endl;
    }
    return 0;
}