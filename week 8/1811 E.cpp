#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int t, A[20], cnt;
LL k, pow10[18], dp[20][2];

LL dfs(int pos, bool limit) {
	//cout << pos << '\n';
	if (pos <= 0)
		return 1;
	if (dp[pos][limit] != -1)
		return dp[pos][limit];
	
	LL ans = 0;
	int sup = (limit ? A[pos] : 9);
	for (int i = 0; i <= sup; ++i) {
		if (i == 4)
			continue;
		ans += dfs(pos - 1, limit && (i == A[pos]));
	}

	dp[pos][limit] = ans;
	return ans;
}

void del4(LL x) {
	int B[20];
	LL y = x, cnt = 0;
	while (y) {
		int r = y % 10;
		B[++cnt] = r;
		y /= 10;
	}
	for (int i = cnt; i >= 1; --i) {
		if (B[i] == 4) {
			cout << 3;
			for (int j = i - 1; j >= 1; --j) {
				cout << 9; 
			}
			break;
		} else {
			cout << B[i];
		}	
	}
	cout << '\n';
}

LL f(LL x) {
	memset(dp, -1, sizeof(dp));
	cnt = 0;
	while (x) {
		int r = x % 10;
		x /= 10;
		A[++cnt] = r;
	}
	return dfs(cnt, 1) - 1;
}

void solve() {
	cin >> k;
	LL l = 1, r = 1e14;
	while (l < r) {
		LL mid = (l + r) / 2;
		if (f(mid) > k) {
			r = mid - 1;
		} else if (f(mid) < k) {
			l = mid + 1;
		} else {
			l = r = mid;
		}
	}//cout << l << '\n';
	del4(l);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	pow10[0] = 1;
	for (int i = 1; i <= 12; ++i)
		pow10[i] = pow10[i - 1] * 10;
	cin >> t;
	while (t--) {
		solve();
	}
	
	return 0;
}
