#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>

struct Point {
    int x, y;
    Point(int xx, int yy) : x(xx), y(yy) {}
    bool operator<(const Point& other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
};

int rows = 5000;
int cols = 4000;
int MINH = 1200;
int MAXH = 3500;

// Generuje dynamicznie tablicę wysokości
int** genHeightMap() {
    int** height = new int*[rows];
    for (int i = 0; i < rows; ++i)
        height[i] = new int[cols];
    for(int i = 0; i < rows; ++i)
        for(int j = 0; j < cols; ++j)
            height[i][j] = MINH + rand() % (MAXH - MINH + 1);
    return height;
}

// Losuje dwa różne punkty na mapie
void randomPoints(Point& p1, Point& p2) {
    do {
        p1.x = rand() % rows;
        p1.y = rand() % cols;
        p2.x = rand() % rows;
        p2.y = rand() % cols;
    } while (p1.x == p2.x && p1.y == p2.y);
}

// Zwraca sąsiadów 8-kierunkowych
std::vector<Point> getNeighbors(const Point& p) {
    std::vector<Point> result;
    for (int dx = -1; dx <=1; ++dx)
        for (int dy = -1; dy <=1; ++dy) {
            if(dx == 0 && dy == 0) continue;
            int nx = p.x + dx;
            int ny = p.y + dy;
            if(nx >= 0 && nx < rows && ny >= 0 && ny < cols)
                result.push_back(Point(nx, ny));
        }
    return result;
}

// Losowo generuje ścieżkę z p1 do p2, ruch tylko do nieodwiedzonych sąsiadów
std::vector<Point> randomPath(Point start, Point end) {
    std::set<Point> visited;
    std::vector<Point> path;
    path.push_back(start);
    visited.insert(start);

    Point curr = start;
    while (!(curr.x == end.x && curr.y == end.y)) {
        auto neighbors = getNeighbors(curr);
        // Odfiltruj odwiedzone
        std::vector<Point> candidates;
        for (auto& n : neighbors)
            if (visited.find(n) == visited.end())
                candidates.push_back(n);

        // Jeżeli nie ma nieodwiedzonych sąsiadów, przerywamy (ślepa uliczka)
        if (candidates.empty())
            break;

        // Preferuj ruch w stronę celu (heurystyka)
        std::sort(candidates.begin(), candidates.end(), [&](const Point& a, const Point& b){
            int da = std::abs(a.x - end.x) + std::abs(a.y - end.y);
            int db = std::abs(b.x - end.x) + std::abs(b.y - end.y);
            return da < db;
        });

        // Wybierz losowego z 3 najbliższych
        int take = std::min(int(candidates.size()), 3);
        int idx = rand() % take;
        curr = candidates[idx];
        path.push_back(curr);
        visited.insert(curr);
    }
    return path;
}

// Oblicza średnie nachylenie ścieżki w stopniach
double averageSlope(const std::vector<Point>& path, int** height) {
    double sumSlope = 0.0;
    int count = 0;
    for (size_t i = 1; i < path.size(); ++i) {
        int x1 = path[i-1].x, y1 = path[i-1].y;
        int x2 = path[i].x, y2 = path[i].y;
        double dz = height[x2][y2] - height[x1][y1];
        double dx = x2 - x1, dy = y2 - y1;
        double dist = sqrt(dx*dx + dy*dy); // w metrach (krok siatki 1m)
        if(dist == 0) continue;
        double slopeRad = atan2(dz, dist); // atan2 - dz/dl
        double slopeDeg = slopeRad * 180.0 / M_PI;
        sumSlope += std::abs(slopeDeg);
        ++count;
    }
    return count ? sumSlope / count : 0.0;
}

int main() {
    srand(time(0));
    int** height = genHeightMap();
    Point p1(0,0), p2(0,0);
    randomPoints(p1, p2);

    std::cout << "Punkt 1: (" << p1.x << "," << p1.y << "), h=" << height[p1.x][p1.y] << "\n";
    std::cout << "Punkt 2: (" << p2.x << "," << p2.y << "), h=" << height[p2.x][p2.y] << "\n";

    std::vector<Point> path = randomPath(p1, p2);

    std::cout << "Długość drogi: " << path.size() << " punktów\n";
    double avgSlope = averageSlope(path, height);
    std::cout << "Średnie nachylenie drogi: " << avgSlope << " stopni\n";

    for (int i = 0; i < rows; ++i)
        delete[] height[i];
    delete[] height;
    return 0;
}