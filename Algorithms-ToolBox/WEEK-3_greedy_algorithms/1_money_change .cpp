#include <iostream>
using namespace std;




int main()
{
	int a;
	cin >> a;
	int a10 = a / 10;
	a -= a10 * 10;
	int a5 = a / 5;
	a -= a5 * 5;
	int a1 = a;
	a -= a1;
	cout << a10 + a5 + a1 << endl;

	return 0;
}
