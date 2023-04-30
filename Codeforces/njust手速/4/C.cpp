#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t = 1, n;
ll a, b, x;
//an + bf(n)
ll f(ll x) {
	int cnt = 0;
	while (x) {
		x /= 10;
		cnt++;
	}
	return cnt;
}

ll g(ll x) {
	return a * x + b * f(x);
}

void solve() {
	cin >> a >> b >> x;
	
	ll l = 1, r = (ll)1e9;
	if (x < a + b) {
		cout << 0;
		return;
	}
	while (l < r) {
		ll mid = (l + r) / 2;
		if (x < g(mid)) {
			r = mid - 1;
		} else if (x == g(mid)) {
			cout << mid;
			return;
		} else {
			if (g(mid + 1) <= x)
				l = mid + 1;
			else {
				cout << mid;
				return;
			}
		}
	}
	cout << l;
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
