#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n, q;
const LL P = 1e9 + 7;

void solve() {
	cin >> n >> q;
	vector<int> a(n + 1), s(n + 1, 0);
	//	vector<int> vis;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	int cnt = 0;
	for (int i = 2; i < n; ++i) {
		if (a[i - 1] >= a[i] && a[i] >= a[i + 1]) {
			s[i] = s[i - 1] + 1;
		} else {
			s[i] = s[i - 1];
		}
	}
	
	while (q--) {
		int l, r;
		cin >> l >> r;
		if (l == r)
			cout << "1\n";
		else {
			int ans = (r - l + 1) - (s[r - 1] - s[l]);
			cout << ans << '\n';			
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}
