#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int t, n;
int a[60];

void solve() {
	cin >> n;
	ll s = 1;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		s *= a[i];
	}
	
	cout << 2022 * (s + n - 1) << '\n';
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
