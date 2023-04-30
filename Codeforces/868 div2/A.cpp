#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n, k;
const LL P = 1e9 + 7;


void solve() {
	cin >> n >> k;
	bool ok = 0;
	for (int i = 0; i <= n; ++i) {
		int j = n - i;
		int num = i * (i - 1) / 2 + j * (j - 1) / 2;
		if (num == k) {
			cout << "YES\n";
			for (int r = 1; r <= i; ++r)
				cout << 1 << ' ';
			for (int r = 1; r <= j; ++r)
				cout << -1 << ' ';
			cout << '\n';
			return;
		}
	}
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
