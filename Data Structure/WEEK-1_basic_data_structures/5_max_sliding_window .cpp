// This solution considered as WRONG
// If you can help or spot the mistake DO NOT HESITATE

#include <iostream>
#include <vector>
#include <stack> 

using namespace std;

void max_sliding_window(vector<int> const& A, int w) {

    vector<int> win(A.size() + 1, INT_MIN);
    int s = 0, e = 0;
    for (int i = 0; i < A.size(); i++) {
        if (i >= w) {
            s++;
            while (win[s] == win[e - 1]) { s++; }
        }
        win[e] = A[i];
        e++;
        while (A[s] < A[i]) {
            s++;
        }
        if (i >= w - 1) {
            cout << win[s];
            if (i != A.size() - 1) {
                cout << " ";
            }
        }

    }

    return;
}


int main() {
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;

    max_sliding_window(A, w);

    return 0;
}
