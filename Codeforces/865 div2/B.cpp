#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n;
const LL P = 1e9 + 7;
int a[200009][2];

void solve() {
	cin >> n;
	a[1][0] = 2 * n, a[n][1] = 2 * n - 1;
	int mi = 1, ma = 2 * n - 2;
	for (int i = 2; i <= n; ++i) {
		if (i % 2 == 0) {
			a[i][0] = mi + 1;
			a[i - 1][1] = mi;
			mi += 2;
		} else {
			a[i][0] = ma;
			a[i - 1][1] = ma - 1;
			ma -= 2;
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		cout << a[i][0] << ' ';
	}
	cout << '\n';
	for (int i = 1; i <= n; ++i) {
		cout << a[i][1] << ' ';
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
