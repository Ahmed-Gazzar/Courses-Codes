#include <iostream>
#include <vector> 

using namespace std;
using std::vector;
using std::swap;
using std::string;



int edit_distance(const string& str1, const string& str2) {
	int l1 = str1.length();
	int l2 = str2.length();
	vector<vector<int>> res(l1 + 1, vector<int>(l2 + 1, 0));
	for (int i = 0; i <= l1; i++) {
		res[i][0] = i;
	}
	for (int i = 0; i <= l2; i++) {
		res[0][i] = i;
	}

	for (int i = 1; i <= l1; i++) {
		for (int j = 1; j <= l2; j++) {
			if (str1[i - 1] == str2[j - 1]) {
				res[i][j] = min(min(res[i - 1][j] + 1, res[i][j - 1] + 1), res[i - 1][j - 1]);
			}
			else {
				res[i][j] = min(min(res[i - 1][j] + 1, res[i][j - 1] + 1), res[i - 1][j - 1] + 1);
			}
		}
	}



	return res[l1][l2];
}


int main() {
	string str1;
	string str2;
	std::cin >> str1 >> str2;
	std::cout << edit_distance(str1, str2) << std::endl;
	return 0;
}
