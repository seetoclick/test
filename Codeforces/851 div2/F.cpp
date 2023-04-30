#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t = 1, n, a[200008], dp[200008][2];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	if (n % 2 == 0) {
		ll ans1 = 0;
		for (int i = 1; i <= n; i += 2)
			ans1 += a[i];
		ll ans2 = 0;
		for (int i = 1; i <= n; i += 2)
			ans2 += a[i];
		cout << max(ans1, ans2);
		return;
	}
	else {
		for (int i = 1; i <= n; ++i) {
			
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	//cin >> t;
	while (t--) {
		solve();
	}
	
	return 0;
}
