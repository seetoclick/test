#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 1000;
int n, k;
LL C[N + 5][N + 5], D[N + 5], dp[N + 5];

void solve() {
	cin >> n >> k;
	for (int i = 1; i <= N; ++i) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; ++j)
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
	}
	D[1] = 0, D[2] = 1;
	for (int i = 3; i <= N; ++i)
		D[i] = (i - 1) * (D[i - 1] + D[i - 2]);
	
	dp[n] = 1;
	for (int i = n; i >= n - k + 1; --i) {
		dp[i - 1] = dp[i] + C[n][i - 1] * D[n - i + 1];
	}
	cout << dp[n - k] << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}
