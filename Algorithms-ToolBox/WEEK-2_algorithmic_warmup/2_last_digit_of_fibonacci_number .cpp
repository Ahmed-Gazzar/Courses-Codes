#include <iostream>
#include <vector> 
using namespace std;


int get_fibonacci_last_digit(int n){

    vector<long long>fib;
    fib.push_back(0);
    fib.push_back(1);
    for (int i = 2; i < 60; i++) {
        int x = fib[i - 1] + fib[i - 2];
        fib.push_back(x % 10);
    }
    int x = n % 60;
    return fib[x];
}



int main() {

    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit(n);
    std::cout << c << '\n';
    return 0;
}



