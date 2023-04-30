#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int t, n, m;

void solve() {
	cin >> n >> m;
	vector<int> a(n + 1);
	
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	if (n == 1) {
		cout << "0\n";
		return;
	}
	
	int cnt = 0;
	LL S = 0;
	priority_queue<int, vector<int>, greater<int>> q1;
	for (int i = m + 1; i <= n; ++i) {
		S += a[i];
		if (a[i] < 0)
			q1.push(a[i]);
		while (S < 0) {
			cnt++;
			int p = q1.top();
			q1.pop();
			S -= 2 * p;
		}
	}
	
	S = 0;
	priority_queue<int> q2;
	for (int i = m; i >= 2; --i) {
		S += a[i];
		if (a[i] > 0)
			q2.push(a[i]);
		while (S > 0) {
			cnt++;
			int p = q2.top();
			q2.pop();
			S -= 2 * p;
		}
	}
	
	cout << cnt << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> t;
	while (t--) {
		solve();		
	}
	
	return 0;
}
