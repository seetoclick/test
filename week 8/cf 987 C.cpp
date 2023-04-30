#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const LL inf = 1e16;
LL s[3033], c[3033], dp[3033];

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) 
		cin >> s[i];
	for (int j = 1; j <= n; ++j)
		cin >> c[j];
	
	for (int i = 2; i <= n; ++i) {
		dp[i] = inf;
		for (int j = 1; j < i; ++j) {
			if (s[j] < s[i]) {
				dp[i] = min(dp[i], c[i] + c[j]);
			}
		}
	}
	
	LL ans = inf;
	for (int i = 3; i <= n; ++i) {
		for (int j = 2; j < i; ++j) {
			if (s[j] < s[i]) {
				ans = min(ans, c[i] + dp[j]);
			}
		}
	}
	
	if (ans != inf)
		cout << ans;
	else
		cout << "-1\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}
