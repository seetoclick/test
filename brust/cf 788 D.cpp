#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n;

LL cal(LL line) {
	LL z = line / 3, x = z, y = z;
	if (line % 3 == 1) {
		y++;
	} else if (line % 3 == 2) {
		y++, x++;
	}
	return 2 * (x * y + x * z + y * z);
}

void solve() {
	cin >> n;
	LL l = 1, r = 1e9;
	while (l < r) {
		LL m = (l + r) / 2;
		LL rel = cal(m);
		if (rel < n) {
			l = m + 1;
		} else if (rel > n) {
			r = m;
		} else {
			r = l = m;
		}
	}
	cout << l << '\n';
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
