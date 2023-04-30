#include <bits/stdc++.h>
using namespace std;

int n;
double dp[303][303][303];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	dp[1][0][0] = n, dp[0][1][0] = 2 * n, dp[0][0][1] = 3 * n;
	//dp[i][j][k] = 1/n(dp[i-1][j][k] + dp[i][j-1][k] + dp[i][j][k-1])
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; i + j <= n; ++j) {
			for (int k = 0; i + j + k <= n; ++k) {
				if (i > 0)
					dp[i][j][k] = 1.0 / (i + j + k) * dp[i - 1][j]
			}
		}
	}
}
