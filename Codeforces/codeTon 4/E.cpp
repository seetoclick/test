#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n, c, d;
LL a[100009];

void solve() {
	cin >> n >> c >> d;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	
	vector<LL> dp(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		
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
