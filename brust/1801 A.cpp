#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int t, n, m;
const LL P = 1e9 + 7;


void solve() {
	cin >> n >> m;
	cout << n * m << '\n';
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j)
			cout << 1000LL * i + j << ' ';
		cout << '\n';
	}
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
