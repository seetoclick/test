#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n, m;
const LL P = 1e9 + 7;

void solve() {
	cin >> n >> m;
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int ans = 4;
	if (x1 == 1 || x1 == n) {
		if (y1 == 1 || y1 == m)
			ans = min(ans, 2);
		else
			ans = min(ans, 3);
	} else {
		if (y1 == 1 || y1 == m)
			ans = min(ans, 3);
		else
			ans = min(ans, 4);
	}
	if (x2 == 1 || x2 == n) {
		if (y2 == 1 || y2 == m)
			ans = min(ans, 2);
		else
			ans = min(ans, 3);
	} else {
		if (y2 == 1 || y2 == m)
			ans = min(ans, 3);
		else
			ans = min(ans, 4);
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
