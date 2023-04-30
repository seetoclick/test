#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const LL P = 1e9 + 7;
const int N = 2e5;

int t, n, m;
LL cnt[10][N + 50];

void init() {
	cnt[0][0] = 1;
	for (int i = 1; i <= N + 20; ++i) {
		LL ans = 0;
		for (int j = 0; j <= 9; ++j) {
			if (j == 0) {
				cnt[0][i] = cnt[9][i - 1] % P;
			} else if (j == 1) {
				cnt[1][i] = (cnt[0][i - 1] + cnt[9][i - 1]) % P;	
			} else {
				cnt[j][i] = cnt[j - 1][i - 1] % P;
			}
			ans += cnt[j][i];
		}
	}
}

void solve() {
	cin >> n >> m;
	LL ans = 0;
	while (n) {
		int r = n % 10;
		LL tmp = 0;
		for (int i = 0; i <= 9; ++i) {
			tmp = (tmp + cnt[i][m + r]) % P;
		}	
		ans = (ans + tmp) % P;
		n /= 10;
	}
	cout << ans << '\n';;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	init();
	cin >> t;
	while (t--) {
		solve();
	}
	
	return 0;
}
