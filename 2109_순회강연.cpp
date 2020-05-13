#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Lecture {
	int p, d;
};

bool cmp(Lecture u, Lecture v) {
	return u.d > v.d;
}

int main() {
	int n;
	cin >> n;
	vector <Lecture> a(n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i].p, &a[i].d);
	}
	sort(a.begin(), a.end(), cmp);
	priority_queue <int> q;

	int k = 0;
	int answer = 0;
	for (int i = 10000; i >= 1; i--) {

		while (k<n && a[k].d == i) {
			q.push(a[k].p);
			k++;
		}
		if (!q.empty()){
			answer += q.top();
			q.pop();
		}

	}
	cout << answer << '\n';
	return 0;
}