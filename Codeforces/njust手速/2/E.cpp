#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t = 1, n, k;
const ll P = 1e9 + 7;
ll dp[100009];

ll qpow(ll a, int n) {
	ll rel = 1;
	while (n) {
		if (n & 1)
			rel = (rel * a) % P;
		a = (a * a) % P;
		n /= 2;
	}
	return rel;
}

void solve() {
	cin >> n >> k;
	for (int i = k; i >= 1; i--) {
		ll num = k / i;
		dp[i] = qpow(num, n); //lgn
		for (int j = 2 * i; j <= k; j += i) // k/i
			dp[i] = (dp[i] + P - dp[j]) % P;
	}
	
	ll ans = 0;
	for (int i = 1; i <= k; ++i)
		ans = (ans + i * dp[i]) % P;
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
