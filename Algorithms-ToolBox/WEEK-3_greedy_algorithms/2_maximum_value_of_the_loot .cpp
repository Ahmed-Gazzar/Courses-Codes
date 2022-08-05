#include <iostream>
#include <vector>
#include<algorithm>

using std::vector;

double get_optimal_value(double c, vector<int> w, vector<int> v) {
    double value = 0.0;
    double totalw=0;
    double totalv = 0;
    vector<double> v_w;
    vector<double> v_w0;
    for (int i = 0; i < v.size(); i++) {
        double v__w = v[i] / w[i];
        double v__w1 = v[i] % w[i];
        double v__w2 = v__w1/w[i];
        v_w.push_back(v__w + v__w2);
        v_w0.push_back(v__w + v__w2);
        totalw += w[i];
        totalv += v[i];
    }
    if (totalw <= c) { return totalv; }
    /////////////////////////////////////////////
    vector<int> max;
    for (int i = 0; i < v.size(); i++) {
        int maxEl = std::max_element(v_w.begin(), v_w.end()) - v_w.begin();
        max.push_back(maxEl);
        v_w[maxEl]=0;
    }
    ////////////////////////////////////////////
    for (int i = 0; i < v.size(); i++) {
        int index = max[i];
        int subload = (w[index]>c) ? (c) : (w[index]);
        c -= subload;
        value += (double)subload * v_w0[index];
        if (c == 0) { return value; }
    }
    return value;
}

int main() {
    int n;
    int capacity;
    std::cin >> n >> capacity;
    vector<int> values(n);
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        std::cin >> values[i] >> weights[i];
    }

    double optimal_value = get_optimal_value(capacity, weights, values);

    std::cout.precision(10);
    std::cout << optimal_value << std::endl;
    return 0;
}

