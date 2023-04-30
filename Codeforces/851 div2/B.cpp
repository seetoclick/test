#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t, n;

void solve() {
	cin >> n;
	if (n % 2 == 0) {
		cout << "No\n";
		return;
	}
	
	int k = (n + 1) / 2;
	
	for (int i = 1; i <= k; ++i) {
		cout << 2 * i - 1 << ' ' << 4 * k - 1 - i << '\n';
	}
	for (int i = 1; i <= k - 1; ++i) {
		cout << 2 * i << ' ' << 3 * k - 1 - i << '\n';
	}
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
