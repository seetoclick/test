#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n, m, k;
LL f[1024][1024];
const LL P = 1e9 + 7;
string s;

void init() {
	for (int i = 1; i <= 1000; ++i) {
		f[i][0] = f[i][i] = 1;
		for (int j = 1; j < i; ++j)
			f[i][j] = (f[i - 1][j] + f[i - 1][j - 1]) % P;
	}
}

void solve() {
	cin >> n >> k;
	vector<int> a(n);
	vector<int> cnt(n + 1, 0);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	sort(a.begin(), a.end());
	
	LL ans = 1;
//	for (int i = n - 1; i >= 0; ) {
//		int num = cnt[a[i]];
//		if (num + n - i - 1 <= k) {
//			if (num + n - i - 1 == k)
//				break;
//			else
//				i -= num;
//		}
//		else {
//			ans = f[cnt[a[i]]][n - k - i + num - 1];
//			break;
//		}
//	}
	for (int i = n; i >= 0; --i) {
		int num = cnt[i];
		if (num >= k) {
			ans = f[num][num - k];
			break;
		} else {
			k -= num;
		}
	}

	cout << ans << '\n';
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
