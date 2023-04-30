#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int t, n;

void solve() {
	cin >> n;
	while (n--) {
		char x, y;
		cin >> x >> y;
		if (x == '0') {
			cout << 1 << '\n';
		}
		else if (y == '1') {
			cout << 2 << '\n';
		}
		else {
			cout << 3 << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	
	return 0;
}
