#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int op[4];
int n;
int cal(vector <int>&a, vector<int> &d) {
	int ret = a[0];
	for (int i = 0; i < a.size()-1; i++) {
		if (d[i] == 0)ret += a[i+1];
		if (d[i] == 1)ret -= a[i+1];
		if (d[i] == 2)ret *= a[i+1];
		if (d[i] == 3)ret /= a[i+1];
	}
	return ret;
}
int main() {
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}
	vector <int> d;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < op[i]; j++) {
			d.push_back(i);
		}
	}
	int max = 0;
	int min = 1000000000;
	do {
		int tmp = cal(a, d);
		if (tmp > max) max = tmp;
		if (tmp < min) min = tmp;
	} while (next_permutation(d.begin(), d.end()));
	printf("%d\n%d", max, min);
	return 0;
}