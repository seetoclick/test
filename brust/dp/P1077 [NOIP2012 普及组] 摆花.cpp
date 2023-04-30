#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const LL P = 1e6 + 7;
int n, m;
int a[1024];
LL S[1024], tmpS[1024], dp[1024][1024];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	LL sum = 0;	
	dp[1][0] = 1, S[0] = 1;
	for (int j = 1; j <= a[1]; ++j) {
		dp[1][j] = 1;
		S[j] = S[j - 1] + dp[1][j];
	}
	sum = a[1];
	for (int i = 2; i <= n; ++i) {
		sum += a[i];
		tmpS[0] = 1;
		for (int j = 1; j <= sum; ++j) {
			int L = max(0, j - a[i]), R = min(sum - a[i], (LL)j);
		    if (L == 0)
				dp[i][j] = S[R];
			else
				dp[i][j] = (S[R] + P - S[L - 1]) % P;
			//cout << i << ' ' << j << ' ' << dp[i][j] << '\n';
			tmpS[j] = (tmpS[j - 1] + dp[i][j]) % P;
		}
		for (int j = 1; j <= sum; ++j)
			S[j] = tmpS[j];
	}
	
	cout << dp[n][m];
	return 0;
}


