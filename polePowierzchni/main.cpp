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
        double ax = i, ay = j, az = height[i][j];
        double bx = i+1, by = j, bz = height[i+1][j];
        double cx = i, cy = j+1, cz = height[i][j+1];
        double abx = bx - ax, aby = by - ay, abz = bz - az;
        double acx = cx - ax, acy = cy - ay, acz = cz - az;
        double nx = aby * acz - abz * acy;
        double ny = abz * acx - abx * acz;
        double nz = abx * acy - aby * acx;
        double area1 = 0.5 * sqrt(nx*nx + ny*ny + nz*nz);

        // Trójkąt 2: (i+1,j), (i+1,j+1), (i,j+1)
        ax = i+1; ay = j; az = height[i+1][j];
        bx = i+1; by = j+1; bz = height[i+1][j+1];
        cx = i; cy = j+1; cz = height[i][j+1];
        abx = bx - ax; aby = by - ay; abz = bz - az;
        acx = cx - ax; acy = cy - ay; acz = cz - az;
        nx = aby * acz - abz * acy;
        ny = abz * acx - abx * acz;
        nz = abx * acy - aby * acx;
        double area2 = 0.5 * sqrt(nx*nx + ny*ny + nz*nz);

        total_area += area1 + area2;
    }
}

    std::cout << "Pole powierzchni terenu: " << total_area << " m^2" << std::endl;

    for (int i = 0; i < rows; ++i)
        delete[] height[i];
    delete[] height;

    return 0;
}