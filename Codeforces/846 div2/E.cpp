#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t, n;
const ll P = 1e9 + 7;
ll L, R;

bool check(ll k) {
	ll m;
	if (L % k == 0) {
		m = L / k;
	} else {
		m = L / k + 1;
	}
	
	if (m <= R / k - 1)
		return true;
	else
		return false;
}

void solve() {
	cin >> L >> R;
	ll ans = (R - L ) / 2;//cout << ans << ' ';
	for (ll k = (R - L) / 2 + 1; ; ++k) {
		if (check(k) == false)
			break;
		ans++;
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
