#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t, n, w, h;

void solve() {
	cin >> n >> w >> h;
	
	int L = -1e9, R = 1e9;
	vector<int> a(n + 1), b(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
	}	
	
	for (int i = 1; i <= n; ++i) {
		int l = b[i] + h - a[i] - w;
		int r = b[i] - h - a[i] + w;
		if (l > R || r < L) {
			cout << "NO\n";
			return;
		}
		L = max(L, l);
		R = min(R, r);
	}
	
	cout << "YES\n";
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
