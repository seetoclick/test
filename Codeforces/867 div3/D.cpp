#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n;
const LL P = 1e9 + 7;


void solve() {
	cin >> n;
	if (n == 1)
		cout << "1\n";
	else {
		if (n % 2 == 1)
			cout << "-1\n";
		else {
			cout << n << ' ';
			for (int i = 2; i <= n; i += 2) {
				cout << n - i + 1 << ' ';
				if (i != n)
					cout << i << ' ';
			}
			cout << '\n';
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
