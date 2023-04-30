#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n, k;
const LL P = 1e9 + 7;
string s;

void solve() {
	cin >> n >> k;
	vector<LL> p(n + 1);
	cin >> p[1];
	
	LL s = 0, ans = 0;
	for (int i = 2; i <= n; ++i) {
		cin >> p[i];
		ans = max(ans, (100 * p[i] - 1) / k + 1 - s);
		s += p[i];
	}
	
	cout << max(0LL, ans - p[1]) << '\n';
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
