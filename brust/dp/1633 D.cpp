#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 1e3;
int t, n, k;
int a[N + 5], b[N + 5], c[N + 5], S[N + 5];
LL dp[N * 12 + 5];

void init() {
	for (int i = 1; i <= N; ++i)
		a[i] = 20;
	a[1] = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = i; j >= 1; --j) {
			if (i + i / j > N)
				break;
			a[i + i / j] = min(a[i + i / j], a[i] + 1);			
		}
	}
}

void solve() {
	cin >> n >> k;
	k = min(k, n * 12);
	for (int i = 0; i <= k; ++i)
		dp[i] = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];		
		b[i] = a[b[i]];
		S[i] = S[i - 1] + b[i];	
		//cout << b[i] << ' ';
	}//cout << '\n';
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
	}
	
	LL ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int v = min(S[i], k); v >= 0; --v) {
			if (v >= b[i])
				dp[v] = max(dp[v], dp[v - b[i]] + c[i]);
			ans = max(ans, dp[v]);
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	init();
	cin >> t;
	while (t--) {
		solve();		
	}
	
	return 0;
}
