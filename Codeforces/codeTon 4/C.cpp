#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n, c, d;
LL a[100009];

void solve() {
	cin >> n >> c >> d;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	
	LL cost = 0, ans = 1e16;
	int id = 1;
	for (int i = 1; i <= n; ++i) {
		if (a[i] > id) {
			if (a[i] - id > 1)
				ans = min(ans, cost + d + (n - i + 1) * c);
			cost += (a[i] - id) * d;
			id = a[i];
			id++;
		} else if (a[i] == id) {
			id++;
		} else {
			cost += c;
		}
		ans = min(ans, cost + (n - i) * c);	//remove
		//cout << id << ' ' << cost << ' ' << ans << '\n';
	}
	cout <<	ans << '\n';
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
