#include <iostream>
#include <vector> 
using namespace std;


long long gcd_naive(long long a, long long b) {

	if (a - b < 0) {
		a = a + b;
		b = a - b;
		a = a - b;
	}
	if (b == 0) {
		return a;
	}

	return gcd_naive(a % b, b);

}



int main() {
	long long a;
	long long b;
	cin >> a >> b;
	std::cout << gcd_naive(a, b) << std::endl;
	return 0;
}
