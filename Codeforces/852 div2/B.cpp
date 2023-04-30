#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t, n;

void solve() {
	ll x, y;
	cin >> x >> y;
	ll n = (x - y) * 2;
	cout << n << '\n';
	for (int i = x; i >= y; --i) {
		cout << i << ' ';
	}
	for (int i = y + 1; i < x; ++i) {
		cout << i << ' ';
	}
	cout << '\n';
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
