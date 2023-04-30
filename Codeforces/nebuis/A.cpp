#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n;
const LL P = 1e9 + 7;


void solve() {
	int x, y;
	cin >> x >> y;
	x = abs(x), y = abs(y);
	int r = min(x, y);
	if (x < y)
		swap(x, y);
	x -= r;
	if (x != 0)
		cout << 2 * r + 2 * x - 1 << '\n';
	else
		cout << 2 * r << '\n';
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
