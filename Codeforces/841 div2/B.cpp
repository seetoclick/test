#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t, n;
const ll P = 1e9 + 7;

void solve() {
	cin >> n;
	ll ans1 = 1;
	if (n % 3 == 0 || n % 3 == 2) {
		ans1 = (n * (n + 1) / 6 % P * (n - 1)) % P;
	}
	else if (n % 3 == 1) {
		ans1 = (n * (n - 1) / 6 % P * (n + 1)) % P;
	}
	ll ans2 = (n * (n + 1) / 2 % P * n) % P;
	cout << (2022ll * (ans1 + ans2)) % P << '\n';
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
