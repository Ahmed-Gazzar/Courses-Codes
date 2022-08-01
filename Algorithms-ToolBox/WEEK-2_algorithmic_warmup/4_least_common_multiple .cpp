#include <iostream>
#include <vector> 

using namespace std;


long long gcd(long long a, long long b) {

	if (a - b < 0) {
		a = a + b;
		b = a - b;
		a = a - b;
	}
	if (b == 0) {
		return a;
	}

	return gcd(a % b, b);
}



int main() {
	
	long long b,p,res,a;
	cin >> a >> b;
	p = gcd(a, b);
	res = a * b / p;
	cout << res << std::endl;


	return 0;
}
