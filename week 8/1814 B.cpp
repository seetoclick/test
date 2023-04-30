#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int t;

void solve() {
	int a, b, ans = 1e9 + 7;
	cin >> a >> b;
	
	for (int i = 1; i <= 50000; ++i) {
		ans = min(ans, i + 1 + (a - 1) / i + (b - 1) / i);
	}
	cout << ans<< '\n';
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
