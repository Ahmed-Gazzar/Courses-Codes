#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int compute_min_refills(int dist, int tank, vector<int>& stops) {
    int current = 0;
    int res = 0;
    if (tank >= dist) { return 0; }

    stops.push_back(dist);

    for (int i = 0; i < stops.size(); i=i) {

        while( i < stops.size()) {
            if (i < stops.size()-1) {
                if ((stops[i + 1] - stops[i]) > tank) {
                    return -1;
                }
            }
            
            if (stops[i]-stops[current] > tank) {
                current =i - 1;
                break;
            }
            i++;
        }
        res++;

    }

    


    return res-1;
}


int main() {
    int dist = 0;
    cin >> dist;
    int max = 0;
    cin >> max;
    int n = 0;
    cin >> n;

    vector<int> stops(n+1);
    stops[0] = 0;
    for (size_t i = 1; i < n+1; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(dist, max, stops) << "\n";

    return 0;
}
