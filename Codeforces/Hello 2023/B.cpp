#include <bits/stdc++.h>
using namespace std;

int t, n;

void solve() {
	cin >> n;
	if (n % 2 == 0) {
		cout << "YES\n";
		for (int i = 1; i <= n / 2; ++i) {
			cout << "1 -1 ";
		}
		cout << '\n';
	}
	else {
		if (n == 3)
			cout << "NO\n";
		else {
			cout << "YES\n";
			int k = (n + 1) / 2, a = k - 2, b = 1 - k;
			cout << a << ' ';
			for (int i = 2; i <= n; i += 2)
				cout << b << ' ' << a << ' ';
			cout << "\n";
		}	
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
