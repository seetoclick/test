#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t = 1, n;

void solve() {
	ll n, x, y;
	cin >> n >> x >> y;
	ll zushu = n /(x + y);
	ll cnt = 0;
	if (n % (x + y) <= x)
		cnt += n % (x + y);
	else	
		cnt += x;
	cout << zushu * x + cnt;
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
