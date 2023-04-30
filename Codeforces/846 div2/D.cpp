#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t, n;
const ll P = 1e9 + 7;

void solve() {
	ll ans = 0;
	while (1) {
		int d, x;
		cin >> d;
		if (d == 0) {
			cout << "! " << ans << endl;
			//cout.flush();
			return;
		} else {
			cout << "- " << (1 << (d - 1)) << endl;
			//cout.flush();
			ans += (1 << (d - 1));
		}
	}
}

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	
	cin >> t;
	while (t--) {
		solve();
	}
	
	return 0;
}
