#include<bits/stdc++.h>
using namespace std;

int n, x, y, a[1009], s[1009];
bool dp[1005][20005], dp2[1005][20005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	
	cin >> n >> x >> y;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];	
		s[i] = s[i - 1] + a[i];	
	}
	
	bool ok1 = 0;
	dp[2][a[1] + 10000] = 1;
	for (int i = 4; i <= n + 1; i += 2) {
		for (int j = 10000 - s[i - 1]; j <= 10000 +  s[i - 1]; ++j)
			dp[i][j] = dp[i - 2][j - a[i - 1]] | dp[i - 2][j + a[i - 1]]; 
			//cout << i << ' ' << j - 10000 << ' ' << dp[i][j] << '\n';
	}
	ok1 = dp[n + 1][x + 10000] | dp[n][x + 10000];
	if (ok1 == 0) {
		cout << "No";
		return 0;
	}

	bool ok2 = 0;
	dp2[1][0 + 10000] = 1;
	for (int i = 3; i <= n + 1; i += 2) {
		for (int j = 10000 - s[i - 1]; j <= 10000 +  s[i - 1]; ++j)
			dp2[i][j] = dp2[i - 2][j - a[i - 1]] | dp2[i - 2][j + a[i - 1]];
			//cout << i << ' ' << j - 10000 << ' ' << dp2[i][j] << '\n';;
	}
	ok2 = dp2[n + 1][y + 10000] | dp2[n][y + 10000];
	if (ok2 == 0) {
		cout << "No";
		return 0;
	}	
	cout << "Yes";
	
	return 0;
}