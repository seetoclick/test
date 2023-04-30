#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const LL INF = 1e18;
int t, n;
LL s;

void solve() {
	cin >> n >> s;
	vector<vector<LL>> dp(n + 1, vector<LL>(2, INF));
	vector<LL> a(n + 1), sup(n + 1), inf(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] >= 2 * s) {	//x[i]'s interval
			sup[i] = a[i] - s;
			inf[i] = s;
		} else {
			sup[i] = min(s, a[i]);
			inf[i] = max(0LL, a[i] - s);
		}
	}
	
	dp[1][0] = a[1] * inf[2], dp[1][1] = a[1] * sup[2];
	for (int i = 2; i <= n - 2; ++i) {
		dp[i][0] = min(dp[i - 1][0] + (a[i] - inf[i]) * inf[i + 1], dp[i - 1][1] + (a[i] - sup[i]) * inf[i + 1]);
		dp[i][1] = min(dp[i - 1][0] + (a[i] - inf[i]) * sup[i + 1], dp[i - 1][1] + (a[i] - sup[i]) * sup[i + 1]);
	}
	cout << min(dp[n - 2][0] + (a[n - 1] - inf[n - 1]) * a[n], dp[n - 2][1] + (a[n - 1] - sup[n - 1]) * a[n]) << '\n';
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
