#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a[20][20];
int go(vector <int> &d, int n) {
	int ret;
	int x=0, y=0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (d[i] == 0 && d[j]==0) {
				x += a[i][j];
			}
			if (d[i] == 1 && d[j] == 1) {
				y += a[i][j];
			}
		}
	}
	ret = x - y;
	if (ret < 0) ret = -ret;
	return ret;
}
int main() {
	int n, ans = -1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	vector <int> d(n);
	for (int i = 0; i < n / 2; i++) {
		d[n -1-i] = 1;
	}
	do {
		int tmp = go(d, n);
		if (ans == -1) ans = tmp;
		if (ans > tmp) ans = tmp;
	} while (next_permutation(d.begin(), d.end()));
	cout << ans;
	return 0;
}