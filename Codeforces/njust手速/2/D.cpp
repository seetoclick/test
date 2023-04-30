#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t = 1, n;
ll dp[300];

void solve() {
	cin >> n;
	for (int i = n; i >= 1; i--) {
		int num = n / i;
		dp[i] = num * num * num;
		for (int j = 2 * i; j <= n; j += i)
			dp[i] -= dp[j];
	}
	
	ll ans = 0;
	for (int i = 1; i <= n; ++i)
		ans += i * dp[i];
	cout << ans;
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
