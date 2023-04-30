#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n, s;

void solve() {
	cin >> n;
	vector<LL> a(n + 1), dp(n + 1);
	LL sum = 0;
	
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];	
		a[i] -= 2 * s;
		sum += a[i];
	}
	a[1] += s, a[n] += s;
	sum += 2 * s;
	
	if
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (t--) {
		solve();		
	}
	
	return 0;
}
