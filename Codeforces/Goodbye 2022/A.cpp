#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t, n, m;
ll a[215], b;

void solve() {
	cin >> n >> m;
	ll s = 0;
	
	for (int i = 1; i <= n + m; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + n + m + 1);
	for (int i = m + 1; i <= m + n; ++i)
		s += a[i];
	
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
