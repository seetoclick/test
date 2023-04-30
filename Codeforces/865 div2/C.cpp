#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n;
const LL P = 1e9 + 7;


void solve() {
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	if (n == 2) {
		if (a[1] > a[2])
			cout << "NO\n";
		else
			cout << "YES\n";
		return;
	} else {
		if (n % 2 == 1)
			cout << "YES\n";
		else {
			for (int i = 1; i <= n - 3; ++i)
				if (a[i + 2] - a[i + 3] <= a[i + 1] - a[i]) {
					cout << "YES\n";
					return;
				}
			cout << "NO\n";
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
