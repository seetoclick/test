#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int t, n;

void solve() {
	cin >> n;
	vector<int> a(n + 1, 0), f(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		f[a[i]] = i;
	}

	int ans = 0;
	int l = 1, r = n, x = n / 2, y = n + 1 - n / 2;
	while (l < r) {
		if (a[l] != x || a[r] != y) {
			ans++;
			int loc1 = f[x], loc2 = f[y];
			a[loc1] = 0, a[loc2] = 0;
			
		} else {
			a[l] = 0, a[r] = 0;
		}
		x--, y++;
		while (!a[l] || !a[r]) {
			if (a[l] == 0)
				l++;
			if (a[r] == 0)
				r--;
		}
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
