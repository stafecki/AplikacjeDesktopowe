#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
double randomTemp() {
    double r = static_cast<double>(rand()) / RAND_MAX; // [0,1]
    return 18.0 + r * (25.0 - 18.0);
}

int main() {
    // jednostki podane w cm
    int step = 10;
    int x = 500;
    int y = 400;
    int z = 270;

    int nx = x/step;
    int ny = y/step;
    int nz = z/step;

    float*** table = new float**[nx];
    for(int i=0; i<nx; i++) {
        table[i] = new float*[ny];
        for(int j=0; j<ny; j++) {
            table[i][j] = new float [nz];
        }
    }
    srand(time(nullptr));

    for(int i=0; i<nx; i++) {
        for(int j=0; j<ny; j++) {
            for(int k=0; k<nz; k++) {
                table[i][j][k] = randomTemp();
            }
        }
    }

    double bestAvg = -1.0;
    string bestType;
    int bestIndex = -1;

    for (int j = 0; j < ny; j++) {
        double sum = 0.0;
        int count = 0;
        for (int i = 0; i < nx; i++) {
            for (int k = 0; k < nz; k++) {
                sum += table[i][j][k];
                count++;
            }
        }
        double avg = sum / count;
        if (avg > bestAvg) {
            bestAvg = avg;
            bestType = "XZ";
            bestIndex = j;
        }
    }

    for (int i = 0; i < nx; i++) {
        double sum = 0.0;
        int count = 0;
        for (int j = 0; j < ny; j++) {
            for (int k = 0; k < nz; k++) {
                sum += table[i][j][k];
                count++;
            }
        }
        double avg = sum / count;
        if (avg > bestAvg) {
            bestAvg = avg;
            bestType = "YZ";
            bestIndex = i;
        }
    }

    int coord = (bestIndex + 1) * step;

    cout << "Najcieplejszy przekroj: " << bestType
         << " na odleglosci " << coord << " cm od sciany "
         << "(srednia temperatura = " << bestAvg << " C)" << endl;

    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            delete[] table[i][j];
        }
        delete[] table[i];
    }
    delete[] table;

    return 0;
}
