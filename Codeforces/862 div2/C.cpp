#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n, m;
const LL P = 1e9 + 7;
LL k[100009];

LL square(LL n) {
	return n * n;
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> k[i];
	k[n + 1] = 0;
	sort(k + 1, k + n + 1);
	
	LL a, b, c;
	LL L, R;
	for (int j = 0; j < m; ++j) {
		cin >> a >> b >> c;
		if (c < 0) {
			cout << "No\n";
			continue;
		}
		
		int id = upper_bound(k + 1, k + n + 1, b) - k;//cout << id << '\n';
		if (id > n)
			id--;
		if (id == 1) {
			if (square(b - k[id]) >= 4 * a * c) {
				cout << "No\n";
				continue;
			} else {
				cout << "Yes\n";
				cout << k[id] << '\n';
			}
		} else {
			if (square(b - k[id]) >= 4 * a * c) {
				if (square(b - k[id - 1]) >= 4 * a * c)
					cout << "No\n";
				else
					cout << "Yes\n" << k[id - 1] << '\n';
			} else {
				cout << "Yes\n" << k[id] << '\n';
			}	
		}
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
}
