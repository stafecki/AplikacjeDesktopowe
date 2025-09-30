#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

int main() {
    int rows = 5000; // 5 km / 1 m
    int cols = 4000; // 4 km / 1 m

    int** height = new int*[rows];
    for (int i = 0; i < rows; ++i)
        height[i] = new int[cols];

    srand(time(0));

    for(int i = 0; i < rows; ++i)
        for(int j = 0; j < cols; ++j)
            height[i][j] = 1200 + rand() % (3500 - 1200 + 1);

    double total_area = 0.0;

    for(int i = 0; i < rows - 1; ++i) {
        for(int j = 0; j < cols - 1; ++j) {
            // Trójkąt 1: (i,j), (i+1,j), (i,j+1)
            double a1 = sqrt(pow(height[i+1][j] - height[i][j], 2) + 1.0); // (i,j)-(i+1,j)
            double b1 = sqrt(pow(height[i][j+1] - height[i][j], 2) + 1.0); // (i,j)-(i,j+1)
            double c1 = sqrt(pow(height[i+1][j] - height[i][j+1], 2) + 2.0); // (i+1,j)-(i,j+1)

            double s1 = (a1 + b1 + c1) / 2;
            double area1 = sqrt(s1 * (s1 - a1) * (s1 - b1) * (s1 - c1));

            // Trójkąt 2: (i+1,j), (i+1,j+1), (i,j+1)
            double a2 = sqrt(pow(height[i+1][j+1] - height[i+1][j], 2) + 1.0); // (i+1,j)-(i+1,j+1)
            double b2 = sqrt(pow(height[i+1][j+1] - height[i][j+1], 2) + 1.0); // (i+1,j+1)-(i,j+1)
            double c2 = sqrt(pow(height[i+1][j] - height[i][j+1], 2) + 2.0); // (i+1,j)-(i,j+1)
            double s2 = (a2 + b2 + c2) / 2;
            double area2 = sqrt(s2 * (s2 - a2) * (s2 - b2) * (s2 - c2));

            total_area += area1 + area2;
        }
    }

    std::cout << "Pole powierzchni terenu: " << total_area << " m^2" << std::endl;

    for (int i = 0; i < rows; ++i)
        delete[] height[i];
    delete[] height;

    return 0;
}