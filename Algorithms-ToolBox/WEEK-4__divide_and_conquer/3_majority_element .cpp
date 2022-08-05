#include <iostream> 
#include <vector> 

using namespace std;
using std::vector;


int get_majority_element(vector<int>& a) {
    sort(a.begin(), a.end()); int q = a.size(); int count = 1;
    for (int i = 1; i < q; i++) {
        if (a[i] != a[i - 1]) {
            count = 1;
        }
        else { count++; }

        if (count * 2 > q) { return 1; }
    }


    return 0;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cin >> a[i];
    }
    std::cout << get_majority_element(a) << '\n';
}
