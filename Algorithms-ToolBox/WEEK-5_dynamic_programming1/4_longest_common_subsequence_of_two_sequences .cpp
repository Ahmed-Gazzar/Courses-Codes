#include <iostream>
#include <vector> 

using namespace std;
using std::vector;
using std::swap;

int f(vector<vector<int>> res, vector<int> a, vector<int> b) {

	int indel = 0, mismatch = 0;
	int l1 = a.size();
	int l2 = b.size();

	int i = l1, j = l2;
	while (i > 0 && j > 0) {
		if (res[i][j] == (res[i - 1][j] + 1)) {
			indel++;
			i--;
		}
		else {
			if (res[i][j] == (res[i][j - 1] + 1)) {
				indel++;
				j--;
			}
			else {
				if (a[i - 1] != b[j - 1] && res[i][j] == (res[i - 1][j - 1] + 1)) {
					mismatch++;
					i--; j--;
				}
				else {
					if (a[i - 1] == b[j - 1] && res[i][j] == (res[i - 1][j - 1])) {
						i--; j--;
					}
				}
			}
		}
	}
	indel += i + j;
	int total = l1 + l2;
	int common2 = total - indel - (2 * mismatch);
	return common2 / 2;
}

int lcs2(vector<int>& a, vector<int>& b) {
	int indel = 0, mismatch = 0;
	int l1 = a.size();
	int l2 = b.size();
	vector<vector<int>> res(l1 + 1, vector<int>(l2 + 1, 0));
	for (int i = 0; i <= l1; i++) {
		res[i][0] = i;
	}
	for (int i = 0; i <= l2; i++) {
		res[0][i] = i;
	}
	for (int i = 1; i <= l1; i++) {
		for (int j = 1; j <= l2; j++) {
			if (a[i - 1] == b[j - 1]) {
				res[i][j] = min(min(res[i - 1][j] + 1, res[i][j - 1] + 1), res[i - 1][j - 1]);
			}
			else {
				res[i][j] = min(min(res[i - 1][j] + 1, res[i][j - 1] + 1), res[i - 1][j - 1] + 1);
			}
		}
	}

	return f(res, a, b);
}

int main() {

	size_t n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	size_t m;
	std::cin >> m;
	vector<int> b(m);
	for (size_t i = 0; i < m; i++) {
		std::cin >> b[i];
	}

	std::cout << lcs2(a, b) << std::endl;


}
