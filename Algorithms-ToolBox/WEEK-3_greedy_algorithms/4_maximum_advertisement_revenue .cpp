#include <algorithm>
#include <iostream>
#include <vector>


using std::vector;

long long max_dot_product(vector<int> a, vector<int> b) {
    long long res = 0;
    for (int i = 0; i < a.size(); i++) {
        int maxEla = std::max_element(a.begin(), a.end()) - a.begin();
        int maxElb = std::max_element(b.begin(), b.end()) - b.begin();
        res += (long long)a[maxEla] * (long long)b[maxElb];
        a[maxEla] = -1000000;
        b[maxElb] = -1000000;
    }
    return res;
}

int main() {
    size_t n;
    std::cin >> n;
    vector<int> a(n), b(n);
    for (size_t i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (size_t i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    std::cout << max_dot_product(a, b) << std::endl;
}
