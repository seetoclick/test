#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n;
const LL P = 1e9 + 7;


void solve() {
	cin >> n;
	vector<int> a(n + 1), b(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i)
		cin >> b[i];
	
	int maxl = 1, maxr = 1;
	int l = 1, r = l;
	while (l < n) {
		r = l;
		//cout << l << ' ';
		while (b[l] <= b[l + 1] && l + 1 <= n)
			l++;//cout << l << '\n';
		if (l + 1 - r > maxr - maxl + 1) {
			maxl = r;
			maxr = l;
		}
		l = l + 1;
	}
	cout << maxl << ' ' << maxr << '\n';
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
