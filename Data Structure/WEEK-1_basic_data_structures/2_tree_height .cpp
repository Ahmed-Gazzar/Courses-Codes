// This solution considered as WRONG
// If you can help or spot the mistake DO NOT HESITATE

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> max_index(vector<int> v) {
	int max = v[0];
	for (size_t i = 0; i < v.size(); i++)
	{
		max = max * (max >= v[i]) + v[i] * (max < v[i]);
	}
	vector<int> res;
	for (size_t i = 0; i < v.size(); i++)
	{
		if (v[i] == max) { res.push_back(i); }
	}
	return res;
}

int max(vector<int> v) {
	int max = v[0];
	for (size_t i = 0; i < v.size(); i++)
	{
		max = max * (max >= v[i]) + v[i] * (max < v[i]);
	}
	return max;
}

bool noZero(vector<int> v) {
	for (size_t i = 0; i < v.size(); i++)
	{
		if (v[i] == 0) { return false; }
	}
	return true;
}

int f(vector<int>& tree, vector<int>& level) {

	if (noZero(level)) {
		return max(level);
	}

	int now = max(level) + 1;
	vector<int> m = max_index(level);
	for (int i = 0; i < m.size(); i++) {
		for (int j = 0; j < tree.size(); j++) {
			if (tree[j] == m[i]) {
				level[j] = now;
			}
		}
	}

	return f(tree, level);
}



int ff(vector<vector<int>>& v, int& root) {
	if (v[root].size() == 0) { return 1; }
	int max = -1;
	for (size_t i = 0; i < v[root].size(); i++)
	{
		int level = ff(v, v[root][i]);
		max += (level - max) * (level > max);
	}
	return max + 1;
}


int main()
{
	int n;
	cin >> n;
	vector<int> tree(n);
	int root = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		tree[i] = x;
		root += i * (x == -1);
	}

	vector<int> level(n, 0);
	level[root] = 1;

	cout << f(tree, level);

}
