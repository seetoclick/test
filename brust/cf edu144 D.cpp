#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 2e5;
int t, n, k, x;
LL a[N + 5], s[N + 5], dp[N + 5][25];

void solve() {
	cin >> n >> k >> x;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}

	//dp[1][0] = a[1]
	LL ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= min(k, i); ++j) {
			if (j == 0) {
				dp[i][0] = max(dp[i - 1][0], 0ll) + a[i] - x;
			} else if (j == i) {
				dp[i][i] = dp[i - 1][i - 1] + a[i] + x;
			} else {
				dp[i][j] = s[i] - s[i - j] + x * j;
				dp[i][j] = max(dp[i][j], dp[i - 1][j] + a[i] - x);
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + a[i] + x);
			}
			if (j + n - i >= k)
				ans = max(ans, dp[i][j]);
			cout << i << ' ' << j << ' ' << dp[i][j] << '\n';
		}
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
