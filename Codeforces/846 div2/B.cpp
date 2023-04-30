#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t, n;
const ll P = 1e9 + 7;

void solve() {
	cin >> n;
	vector<int> a(n + 1);
	cin >> a[1];
	int d = a[1];
	for (int i = 2; i <= n; ++i) {
		cin >> a[i];
		d = __gcd(a[i], d);
	}
	
	vector<ll> s(n + 1);
	s[0] = 0;
	for (int i = 1; i <= n; ++i) {
		a[i] /= d;
		s[i] = s[i - 1] + a[i];
	}
	
	ll ans = 1;
	for (int i = 1; i < n; ++i) {
		ans = max(ans, __gcd(s[i], s[n] - s[i]));
	}
	cout << d * ans << '\n';
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
