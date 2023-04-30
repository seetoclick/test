#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n;
const LL N = 3e5;
LL pay = 1e12;
LL dp[N + 5][3];
string s;

void solve() {
	cin >> s;
	n = s.size();
	s = " " + s;
	
	for (int i = 1; i <= n; ++i) {
		if (s[i] == '0') {
			dp[i][0] = dp[i - 1][0];
			dp[i][1] = dp[i - 1][1] + pay;
			dp[i][2] = dp[i - 1][2] + pay + 1;
		} else {
			dp[i][0] = dp[i - 1][0] + pay + 1;
			dp[i][1] = dp[i - 1][0];
			dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]);
		}		
	}
	
	cout << min(min(dp[n][0], dp[n][1]), dp[n][2]) << '\n';
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
