#include <iostream>
#include <vector> 

using namespace std;


int get_fibonacci_last_digit(long long n) {

    vector<int>fib;
    vector<int>fib0;
    fib.push_back(0);
    fib.push_back(1);
    fib0.push_back(0);
    fib0.push_back(1);
    for (int i = 2; i < 60; i++) {
        int x = fib[i - 1] + fib[i - 2];
        fib.push_back(x % 10);
        fib0.push_back(fib0[i - 1] + fib[i]);
    }
    int x = n % 60;
    long long xx = n / 60;

    return (xx * fib0[59] + fib0[x]) % 10;
}



int main() {

    long long n;
    cin >> n;
    int c = get_fibonacci_last_digit(n);
    cout << c << '\n';
    return 0;
}
