#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n, k;
int a[1024][1024];
const LL P = 1e9 + 7;


void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
		}
	}
	if (n == 1) {
		cout << "Yes\n";
		return;
	}
	int dif = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (a[i][j] != a[n + 1 - i][n + 1 - j])
				dif++;
		}
	}
	dif /= 2;

	cout << k << ' ' << dif << '\n';
	if (dif <= k) {
		if ((k - dif) % 2 == 0 || n % 2 == 1)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	else
		cout << "No\n";	
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
