#include <iostream>
#include <algorithm>
#include <vector> 
#include <chrono> 
#include <iomanip>

using std::vector;
using std::string;
using std::pair;
using std::min;
using namespace std::chrono;
using namespace std;



struct point {
    int x, y;
};
bool compareX(point i1, point i2)
{
    return (i1.x < i2.x);
}
bool compareY(point i1, point i2)
{
    return (i1.y < i2.y);
}
double distance(vector<int> x, vector<int> y) {
    return sqrt((x[0] - x[1]) * (x[0] - x[1]) + (y[0] - y[1]) * (y[0] - y[1]));
}
double dist(point a, point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double minimal_distance(vector<point> p) {
    if (p.size() == 2) {
        return sqrt((p[0].x - p[1].x) * (p[0].x - p[1].x) + (p[0].y - p[1].y) * (p[0].y - p[1].y));
    }
    if (p.size() == 3) {
        double d01 = distance({ p[0].x,p[1].x }, { p[0].y,p[1].y });
        double d12 = distance({ p[1].x,p[2].x }, { p[1].y,p[2].y });
        double d20 = distance({ p[0].x,p[2].x }, { p[0].y,p[2].y });
        return (d01 < d12) ? ((d01 < d20) ? (d01) : (d20)) : ((d12 < d20) ? (d12) : (d20));
    }
    sort(p.begin(), p.end(), compareX);
    int mid = (p.size() - 1) / 2;
    vector<point> p1(p.begin(), p.end() - mid - 1);
    vector<point> p2(p.begin() + mid + 1, p.end());
    double r1 = minimal_distance(p1);
    double r2 = minimal_distance(p2);
    double d = (r1 < r2) ? (r1) : (r2);
    double range1 = p[mid].x - d; double range2 = p[mid].x + d;
    vector<point> pf;
    for (int i = 0; i < p.size(); i++) {
        if (p[i].x >= range1 && p[i].x <= range2) { pf.push_back(p[i]); }
    }
    sort(pf.begin(), pf.end(), compareY);
    int s = 0;
    while (s < pf.size()) {
        point x = pf[s];
        int ss = 1;
        while (ss <= 7 && s + ss < pf.size()) {
            double dd = dist(x, pf[s + ss]);
            d = (dd < d) ? (dd) : (d);
            ss++;
        }
        s++;
    }
    return d;
}



int main() {
    size_t n;
    std::cin >> n;
    vector<point> points(n);
    for (size_t i = 0; i < n; i++) {
        std::cin >> points[i].x >> points[i].y;
    }
    std::cout << std::fixed;
    std::cout << std::setprecision(9) << minimal_distance(points) << "\n";
}
