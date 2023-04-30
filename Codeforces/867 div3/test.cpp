#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n, x, y;
const LL P = 1e9 + 7;
LL f[50];

void init() {
	f[0] = f[1] = 1;
	for (int i = 2; i <= 45; ++i)
		f[i] = f[i - 1] + f[i - 2];
}

void dfs(int n, LL x, LL y) {
		//cout << x << ' ' << y << "\n";	
	if (n == 0) {
		if (x == 1 && y == 1)
			cout << "YES\n";
		else
			cout << "NO\n";
		return;
	}
	
	if (y > f[n]) {
		LL tmp = x;
		x = f[n + 1] - y + 1;
		y = tmp;
		dfs(n - 1, x, y);
	} else {
		LL tmp = x;
		x = f[n - 1] - y + 1;
		y = tmp;
		dfs(n - 1, x, y);
	}
}

void solve() {
	cin >> n >> x >> y;
	dfs(n, x, y);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	init();
	cin >> t;
	while (t--) {
		solve();
	}
	
	return 0;
}
