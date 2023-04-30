#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t = 1, n;

void solve() {
	cin >> n;
	long long ans = 1ll * n * (n + 1) / 2;
	for (int i = 3; i <= n; i += 3)
		ans -= i;
	for (int i = 5; i <= n; i += 5)
		ans -= i;	
	for (int i = 15; i <= n; i += 15)
		ans += i;	
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
