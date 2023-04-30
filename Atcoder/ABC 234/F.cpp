#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const LL P = 998244353;
const int N = 5000;
int t, n, k;
LL C[N + 5][N + 5], dp[N + 5][30];
string s;

void solve() {
	cin >> s;
	int cnt[30], n = s.size();
	for (auto& c : s) {
		cnt[c - 'a' + 1]++;
	}
	for (int i = 1; i <= N; ++i) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; ++j)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % P;
	}
	
	dp[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= 26; ++j) {
			for (int k = 1; k <= min(i, cnt[j]); ++k) {
				dp[i][j] = (dp[i][j] + dp[i - k][j - 1] * C[i][k]) % P;
			}cout << i << ' ' << j << ' ' << dp[i][j] << '\n';
		}
	}
	
	LL ans = 0;
	for (int i = 1; i <= N; ++i) {
		ans = (ans + dp[i][26]) % P;
	}
	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();		
	
	return 0;
}
