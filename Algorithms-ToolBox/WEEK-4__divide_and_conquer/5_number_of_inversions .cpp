#include <iostream>
#include <vector> 

using namespace std;
using std::vector;
using std::swap;

int inv = 0;

vector<int> merge(vector<int> a, vector<int> b) {
    vector<int> res;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) {
            res.push_back(a[i]);
            i++;
        }
        else {
            res.push_back(b[j]);
            j++;
            ::inv++;
        }
    }
    if (i == a.size()) {
        while (j < b.size()) {
            res.push_back(b[j]);
            j++;
        }
    }
    if (j == b.size()) {
        while (i < a.size()) {
            res.push_back(a[i]);
            i++;
        }
    }
    return res;
}

vector<int> mergeSort(vector<int> a) {
    if (a.size() == 1) {
        return a;
    }
    int m = a.size() / 2;
    vector<int> r1(a.begin(), a.begin() + m);
    vector<int> r2(a.begin() + m, a.end());
    vector<int>x1 = mergeSort(r1);
    vector<int>x2 = mergeSort(r2);
    vector<int> x = merge(x1, x2);
    return x;
}



long long get_number_of_inversions(vector<int>& a) {
    vector<int>aa = mergeSort(a);
    return ::inv;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        std::cin >> a[i];
    }

    vector<int> b(a.size());
    std::cout << get_number_of_inversions(a) << '\n';


}
