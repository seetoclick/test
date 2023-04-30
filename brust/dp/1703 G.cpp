#include<bits/stdc++.h>
using namespace std;

long long t, n, k;
long long a[100009];
long long dp[100009][35];

void solve() {
	cin >> n >> k;
	
	dp[0][0] = 0;
	for (int i = 1; i <= n; ++i ) {
		cin >> a[i];
		dp[i][0] = dp[i - 1][0] - k + a[i];
	}
	
	for (long long i = 1; i <= n; ++i ) {
		for (long long j = 1; j <= min(i, 30ll); ++j ) {
			long long temp = (a[i] >> j);
			if (j == 30ll && i > 30) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + temp;	//bad key. but >= 30
			} else {
				dp[i][j] = dp[i - 1][j - 1] + temp;	//bad key
				if (j != i)
					dp[i][j] = max(dp[i - 1][j] - k + temp, dp[i][j]);	//compare bad and good				
			}
		}
	}
	
	long long ans = 0;
	for (long long i = 0; i <= min(n, 30ll); ++i ) 
		ans = max(ans, dp[n][i]);
	cout << ans << '\n';   		
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> t;
	
	while ( t-- ) {
		solve();	    
	}
	
	return 0;
}
