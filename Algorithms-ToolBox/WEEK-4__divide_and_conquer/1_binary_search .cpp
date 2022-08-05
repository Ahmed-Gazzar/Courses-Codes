#include <iostream> 
#include <vector>

using namespace std;
using std::vector;





int binary_search(const vector<int>& a, int x) {
    int left = 0, right = (int)a.size() - 1;
    while (true) {
        int mid = (left + right) / 2;

        if (a[mid] == x) {
            return mid;
        }
        if (a[mid] != x && right <= left) {
            return -1;
        }

        if (x > a[mid]) {
            left = mid + 1;
        }

        if (x < a[mid]) {
            right = mid - 1;
        }

    }

}

int linear_search(const vector<int>& a, int x) {
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] == x) return i;
    }
    return -1;
}


int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        std::cin >> a[i];
    }
    int k;
    std::cin >> k;
    vector<int> b(k);
    for (int i = 0; i < k; ++i) {
        std::cin >> b[i];
    }
    for (int i = 0; i < k; ++i) {
        std::cout << binary_search(a, b[i]) << ' ';
    }
}
