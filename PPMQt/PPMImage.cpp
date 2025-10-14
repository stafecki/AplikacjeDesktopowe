#include "PPMImage.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

PPMImage::PPMImage() : width(0), height(0), maxColor(255), data(nullptr) {}

PPMImage::~PPMImage() {
    delete[] data;
}

bool PPMImage::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) return false;

    string line;
    getline(file, line);
    if (line != "P3") return false;

    // Pomijanie komentarzy
    do { getline(file, line); } while (line[0] == '#');

    istringstream iss(line);
    iss >> width >> height;

    file >> maxColor;
    if (maxColor != 255) return false;

    delete[] data;
    data = new unsigned char[width * height * 3];

    int r, g, b;
    for (int i = 0; i < width * height; ++i) {
        file >> r >> g >> b;
        data[i * 3 + 0] = static_cast<unsigned char>(r);
        data[i * 3 + 1] = static_cast<unsigned char>(g);
        data[i * 3 + 2] = static_cast<unsigned char>(b);
    }
    return true;
}

bool PPMImage::saveToFile(const string& filename) const {
    ofstream file(filename);
    if (!file.is_open() || !data) return false;

    file << "P3\n";
    file << width << " " << height << "\n";
    file << maxColor << "\n";

    for (int i = 0; i < width * height; ++i) {
        file << (int)data[i * 3 + 0] << " "
             << (int)data[i * 3 + 1] << " "
             << (int)data[i * 3 + 2] << "\n";
    }
    return true;
}