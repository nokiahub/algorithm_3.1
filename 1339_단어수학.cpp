#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
vector <char> alphabet;
int value[26];
int n;
int cal(vector <string> &a) {
	int ret = 0;
	for (int i = 0; i < n; i++) {
		string s = a[i];
		int add = 0;
		for (int j = 0; j < s.size(); j++) {
			add += value[s[j] - 65];
			add *= 10;
		}
		add /= 10;
		ret += add;
	}
	return ret;
}
bool compare(string s1, string s2) {
	return s1.size() > s2.size();
}
int main() {
	cin >> n;
	vector <string> a(n);

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		a[i] = s;
	}
	sort(a.begin(), a.end(), compare);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < a[i].size(); j++) {
			alphabet.push_back(a[i][j]);
		}
	}
	sort(alphabet.begin(), alphabet.end());
	alphabet.erase(unique(alphabet.begin(), alphabet.end()), alphabet.end());

	vector <int> number(alphabet.size());
	for (int i = 0; i < number.size(); i++) {
		number[i] = 9 - i;
	}

	int ans = 0;
	do {
		for (int i = 0; i < alphabet.size(); i++) {
			value[alphabet[i]-65] = number[i];
		}
		int tmp = cal(a);
		if (tmp > ans) ans = tmp;
	} while (prev_permutation(number.begin(), number.end()));

	cout << ans;
	return 0;
}