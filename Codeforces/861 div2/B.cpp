#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n, m;
const LL P = 1e9 + 7;

void solve() {
	cin >> n >> m;
	vector<vector<int> > a(m, vector<int>(n));
	LL ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> a[j][i];
	if (n == 1) {
		cout << "0\n";
		return;
	}
	for (int j = 0; j < m; ++j) {
		sort(a[j].begin(), a[j].end());
//		for (auto x : a[j])
//			cout << x << ' ';
//		cout << '\n';
		for (int i = 1; i < n; ++i)
			ans += a[j][i] * (2 * i - n + 1);
		ans -= (n - 1) * a[j][0];
		//cout << ans << '\n';
	}
	cout << ans << '\n';
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
