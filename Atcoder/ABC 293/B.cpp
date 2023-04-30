#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int t, n;

void solve() {
	cin >> n;
	vector<int> a(n + 1), vis(n + 1, 0);
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (vis[i])
			continue;
		if (!vis[a[i]]) {
			vis[a[i]] = 1;
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		if (!vis[i])
			ans++;
	}
	cout << ans << '\n';
	for (int i = 1; i <= n; ++i) {
		if (!vis[i])
			cout << i << ' ';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}
