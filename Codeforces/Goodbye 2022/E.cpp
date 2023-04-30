#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t, n, m;
ll a[115], b[115];

void solve() {
	cin >> n >> m;
	ll s = 0, ans = 0;
	for (int i = 1; i <= n; ++i) {
		s += a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= m; ++i) {
		cin >> b[i];
		if (b[i] - a[1] > 0) {
			ans = s + b[i] - a[1];
		}
		s = s + b[i] - a[1];
		a[1] = b[i];
		sort(a + 1, a + n + 1);
	}
	cout << s << '\n';
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
