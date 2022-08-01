#include <iostream>
#include <vector> 

using namespace std;


long long fibonacci_fast(int n) {

    vector<long long>fib;
    fib.push_back(0);
    fib.push_back(1);
    for (int i = 2; i <= n; i++) {
        fib.push_back(fib[i - 1] + fib[i - 2]);
    }
    return fib[n] ;
}



int main() {
    
    int n = 0;
    std::cin >> n;
    std::cout << fibonacci_fast(n) << '\n';
    
    return 0;
}
