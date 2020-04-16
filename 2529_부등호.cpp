#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool check(vector <int> &v, vector <char> &a) {
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == '>' && v[i] < v[i + 1]) return false;
		if (a[i] == '<' && v[i] > v[i + 1]) return false;
	}
	return true;
}
int main() {

	int k;
	cin >> k;

	vector <char> a;
	for (int i = 0; i < k; i++) {
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}

	//최소값
	vector <int> big(k+1);
	//최대값
	vector <int> small(k+1);

	for (int i = 0; i <= k; i++) {
		small[i] = i;
		big[i] = 9 - i;
	}
	do {
		if (check(small, a)) {
			break;
		}
	} while (next_permutation(small.begin(), small.end()));

	do {
		if (check(big, a)) {
			break;
		}
	} while (prev_permutation(big.begin(), big.end()));

	for (int i = 0; i < k + 1; i++) {
		cout << big[i];
	}
	cout << '\n';
	for (int i = 0; i < k + 1; i++) {
		cout << small[i];
	}
	return 0;
}