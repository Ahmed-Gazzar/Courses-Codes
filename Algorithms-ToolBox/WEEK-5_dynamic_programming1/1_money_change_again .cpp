#include <iostream>
#include <vector> 

using namespace std;
using std::vector;
using std::swap;


int get_change(int x) {


    vector<int> r(x + 5);
    r[1 - 1] = 1;
    r[3 - 1] = 1;
    r[4 - 1] = 1;

    for (int i = 1; i <= x; i++) {
        int q1, q2, q3, w1, w2, w3;

        q1 = i + 1;  w1 = r[q1 - 1];
        if (w1 == 0) { r[q1 - 1] = r[i - 1] + 1; }
        else {
            if (w1 >= (r[i - 1] + 1)) { r[q1 - 1] = r[i - 1] + 1; }
        }

        q2 = i + 3;  w2 = r[q2 - 1];
        if (w2 == 0) { r[q2 - 1] = r[i - 1] + 1; }
        else {
            if (w2 >= (r[i - 1] + 1)) { r[q2 - 1] = r[i - 1] + 1; }
        }

        q3 = i + 4;  w3 = r[q3 - 1];
        if (w3 == 0) { r[q3 - 1] = r[i - 1] + 1; }
        else {
            if (w3 >= (r[i - 1] + 1)) { r[q3 - 1] = r[i - 1] + 1; }
        }

    }



    return r[x - 1];
}

int main() {
    int m;
    std::cin >> m;
    std::cout << get_change(m) << '\n';
}
