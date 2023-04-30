#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, a[20], m, b[100009], x;
int dp[100009];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	cin >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> b[i];
		dp[b[i]] = 2;
	}

	cin >> x;
	
	dp[0] = 1;
	for (int i = 1; i <= x; ++i) {
		if (dp[i] == 2)
			continue;
		for (int j = 1; j <= n; ++j) {
			if (i - a[j] >= 0 && dp[i - a[j]] != 2)
				dp[i] |= dp[i - a[j]];
		}
	}
	
	if (dp[x]) {
		cout << "Yes";
	} else {
		cout << "No";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}
