#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int t, n;
LL pay = 1e12;

void solve() {
	string s;
	cin >> s;
	n = s.size();
	vector<vector<LL>> dp(n, vector<LL>(3));
	
	dp[0][0] = dp[0][1] = dp[0][2] = 0;
	if (s[0] == 0)
		dp[0][1] = pay + 1, dp[0][2] = pay + 1;
	else 
		dp[0][0] = pay + 1;
	for (int i = 1; i < n; ++i) {
		if (s[i] == '0') {
			dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + pay + 1);
			dp[i][1] = dp[i - 1][1] + pay;
			dp[i][2] = dp[i - 1][2] + pay + 1;
		} else {
			dp[i][0] = dp[i - 1][0] + pay + 1;
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][1] + pay + 1);
			dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]);
		}
	}
	
	cout << min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2])) << '\n';
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
