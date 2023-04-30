#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int n, k;
const LL P = 1e9 + 7;
const int N = 2e5;

void solve() {
	cin >> n >> k;
	vector<vector<vector<int>>> mp(2, vector<vector<int>>(N + 5));
	vector<int> a(n + 1);
	LL ans = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		mp[i & 1][a[i]].push_back(i);
		ans += min(k, i) - max(1, (i + k - n)) + 1;
	}	
	ans = (ans - n + k - 1) / 2;
	//cout << ans << '\n';
	for (int i = 1; i <= n; ++i) {
		int L = max(2 + (k - 1) - i, i + 1 - k), R = min(2 * n - (k - 1) - i, i - 2);
		//cout << L << ' ' << R << '\n';
		if (L > R)
			continue;
		int index1 = lower_bound(mp[i & 1][a[i]].begin(), mp[i & 1][a[i]].end(), L) - mp[i & 1][a[i]].begin() + 1;
		int index2 = upper_bound(mp[i & 1][a[i]].begin(), mp[i & 1][a[i]].end(), R) - mp[i & 1][a[i]].begin() + 1;
		if (mp[i & 1][a[i]][index1] < L)
			continue;
		ans -= (index2 - index1);
//		cout << i << ' ' << index1 << ' ' << index2 << '\n';
//		for (auto x : mp[i & 1][a[i]])
//			cout << x << ' ';
//		cout << '\n';
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}
