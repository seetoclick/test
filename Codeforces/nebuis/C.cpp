#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n, x, p;
const LL P = 1e9 + 7;


void solve() {
	cin >> n >> x >> p;
	bool ok = false;
	for (LL i = 1; i <= min(2 * n, p); ++i) {
		LL r = x + i * (i + 1) / 2 % n;
		if (r % n == 0) {
			ok = true;
			break;
		}
	}
	
	if (ok)
		cout << "YES\n";
	else
		cout << "NO\n";
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
