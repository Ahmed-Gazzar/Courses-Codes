#include <iostream>
#include <vector> 

using namespace std;
using std::vector;
using std::swap;

vector<int> r;
int max;


void x(int x) {
    for (int y = 0; y < x * 3 + 1; y++) { r.push_back(0); }

    for (int i = 1; i <= x; i++) {
        int q1, q2, q3, w1, w2, w3;

        q1 = i + 1;  w1 = r[q1 - 1];
        if (w1 == 0) { r[q1 - 1] = r[i - 1] + 1; }
        else {
            if (w1 >= (r[i - 1] + 1)) { r[q1 - 1] = r[i - 1] + 1; }
        }

        q2 = i * 2;  w2 = r[q2 - 1];
        if (w2 == 0) { r[q2 - 1] = r[i - 1] + 1; }
        else {
            if (w2 >= (r[i - 1] + 1)) { r[q2 - 1] = r[i - 1] + 1; }
        }

        q3 = i * 3;  w3 = r[q3 - 1];
        if (w3 == 0) { r[q3 - 1] = r[i - 1] + 1; }
        else {
            if (w3 >= (r[i - 1] + 1)) { r[q3 - 1] = r[i - 1] + 1; }
        }

    }

}
int choice(int n1, int n2, int n3) {
    n1--; n2--; n3--;
    if (r[n1] < r[n2]) {
        if (r[n1] < r[n3]) {
            return n1 + 1;
        }
        else {
            return n3 + 1;
        }
    }
    else {
        if (r[n2] < r[n3]) {
            return n2 + 1;
        }
        else {
            return n3 + 1;
        }
    }
}


vector<int> optimal_sequence(int n) {
    std::vector<int> sequence;
    while (n >= 1) {
        int n1 = ::max, n2 = ::max, n3;
        sequence.push_back(n);
        if (n % 3 == 0) {
            n1 = n / 3;
        }
        if (n % 2 == 0) {
            n2 = n / 2;
        }
        n3 = n - 1;
        if (n3 == 0) { break; }
        n = choice(n1, n2, n3);
    }
    reverse(sequence.begin(), sequence.end());
    return sequence;
}

int main() {
    int n;
    std::cin >> n;
    x(n);
    int aa = r[n - 1];
    ::max = std::max_element(r.begin(), r.end()) - r.begin();
    vector<int> sequence = optimal_sequence(n);
    std::cout << sequence.size() - 1 << std::endl;
    for (size_t i = 0; i < sequence.size(); ++i) {
        std::cout << sequence[i] << " ";
    }
}
