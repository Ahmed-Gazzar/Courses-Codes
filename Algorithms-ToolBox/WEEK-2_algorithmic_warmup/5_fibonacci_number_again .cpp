#include <iostream>
#include <vector> 

using namespace std;


long long fibonacci_fast(long long n,int m) {

    vector<long long>fib;
    fib.push_back(0);
    fib.push_back(1);
    for (int i = 2; i <= n; i++) {

        fib.push_back((fib[i - 1] + fib[i - 2])%m);
    }
    return fib[n];
}

int period(vector<int>fib) {
    int s = fib.size()/2;
    if (s % 2 != 0) { return 0; }
    for (int i = 0; i < s ; i++) {
        if (fib[i] != fib[i + s]) {
            return 0;
        }
    }

    return s;
}


int main() {

    long long n = 0;
    int m = 0, i = 0;
    int Xperiod = 0;
    cin >> n >> m;

    vector<int>fib;
    fib.push_back(0);
    fib.push_back(1);
    for (int i = 2; i <= n; i++) {
        fib.push_back((fib[i - 1] + fib[i - 2]) % m);
        Xperiod = period(fib);
        if (Xperiod != 0) {
            break;
        }
    }
    if(Xperiod==0){ cout << fib[n] << '\n'; }
    else {
        cout << fib[n%Xperiod] << '\n';
    }

    return 0;
}
