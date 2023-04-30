#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int n;

void solve() {
	cin >> n;
	vector<int> a(n + 1), pos(n + 1), dp(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		pos[a[i]] = i;
	}

	for (int i = n; i >= 1; --i) {
		dp[pos[i]] = 0;
		for (int j = pos[i]; j <= n; j += i) {
			if (i < a[j] && dp[j] == 0)
				dp[pos[i]] = 1;
		}
		for (int j = pos[i]; j >= 1; j -= i) {
			if (i < a[j] && dp[j] == 0)
				dp[pos[i]] = 1;
		}		
	}
	
	for (int i = 1; i <= n; ++i) {
		if (dp[i])
			cout << "A";
		else
			cout << "B";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}
