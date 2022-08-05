#include <iostream> 
#include <vector> 

using namespace std;
using std::vector;
using std::swap;



int optimal_weight(int W, const vector<int>& w) {

    vector<vector<int>> d(w.size() + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= w.size(); i++) {
        for (int j = 1; j <= W; j++) {
            int a = d[i - 1][j], b;
            if (j - w[i - 1] < 0) {
                b = 0;
            }
            else {
                b = d[i - 1][j - w[i - 1]] + w[i - 1];
            }
            d[i][j] = max(a, b);
        }
    }
    return d[w.size()][W];
}

int main() {
    int n, W;
    std::cin >> W >> n;
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        std::cin >> w[i];
    }
    std::cout << optimal_weight(W, w) << '\n';
}
