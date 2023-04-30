#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t = 1, n;

void solve() {
	ll L, R;
	cin >> L >> R;
	ll ans = 2020;
	
	for (ll i = L; i <= min(L + 2018, R); ++i) {
		for (ll j = i + 1; j <= min(L + 2018, R); ++j) {
			ans = min(ans, i * j % 2019);
			//cout << i << ' ' << j << ' ' << i * j % 2019 << '\n';
		}
	}
	
	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	//cin >> t;
	while (t--) {
		solve();
	}
	
	return 0;
}
