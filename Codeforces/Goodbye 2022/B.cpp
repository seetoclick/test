#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t, k, n;

void solve() {
	cin >> n >> k;
	if (k == 1) {
		for (int i = 1; i <= n; ++i)
			cout << i << ' ';
	}
	else {
		for (int i = 1; i <= n / 2; ++i) {
			cout << n + 1 - i << ' ' << i << ' ';
		}
		if (n & 1)
			cout << (n + 1) / 2 << ' ';
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> t;
	while (t--) {
		solve();
	}
	
	return 0;
}                                                                                                                                                                              
