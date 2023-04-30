#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n, k, d, w;
const LL P = 1e9 + 7;


void solve() {
	cin >> n >> k >> d >> w;
	vector<int> t(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> t[i];
	}
	
	int ans = 0, r = 1;
	for (int i = 2; ;) {
		int cnt = 1;
		while ((t[i] <= t[r] + d + w) && cnt < k && i <= n) {
			i++;
			cnt++;
		}
		//cout << i << '\n';
		ans++;
		if (i == n + 1)
			break;
		r = i;
		i++;
	}
	
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> t;
	while (t--) {
		solve();
	}
	
	return 0;
}
