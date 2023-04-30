#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int n;
const LL P = 998244353;


void solve() {
	cin >> n;
	vector<LL> a(n + 1), dp(n + 1, 0);
	map<LL, int> mp;
	LL s = 0;
	
	cin >> a[1];
	s = 0, dp[1] = 1;
	for (int i = 2; i <= n; ++i) {
		cin >> a[i];
		dp[i] = 2 * dp[i - 1];
		dp[i] = (dp[i] - dp[mp[s + a[i - 1]]] + P) % P;
		s += a[i - 1];			
		mp[s] = i - 1;//cout << i << ' ' << dp[i] << '\n';
	}
	
	cout << dp[n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();		
	
	return 0;
}
