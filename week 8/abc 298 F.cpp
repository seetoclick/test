#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int n;
map<int, LL> row, col;

void solve() {	
	cin >> n;
	vector<int> x(n + 1), y(n + 1), r(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> y[i] >> r[i];
		row[x[i]] = (row[x[i]] + r[i]);
		col[y[i]] = (col[y[i]] + r[i]);
	}
	
	LL ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans = max(ans, row[x[i]] + col[y[i]] - r[i]);
	}
	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}
