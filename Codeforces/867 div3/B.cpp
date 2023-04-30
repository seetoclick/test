#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n;
const LL P = 1e9 + 7;


void solve() {
	cin >> n;
	vector<LL> a(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	LL neg = 0, pos = 0, ans = 0, maxneg = 2e9, minpos = 2e9, zero = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] > 0) {
			ans = max(ans, pos * a[i]);
			if (a[i] > pos)
				pos = a[i];
			
			if (minpos == 2e9)
				minpos = a[i];
			else
				minpos = min(minpos, a[i]);
		} else if (a[i] < 0) {
			ans = max(ans, neg * a[i]);
			if (a[i] < neg)
				neg = a[i];
			
			if (maxneg == 2e9)
				maxneg = a[i];
			else
				maxneg = max(maxneg, a[i]);			
		} else {
			zero++;
		}
	}
	
	if (zero)
		cout << ans << '\n';
	else {
		if (ans == 0)
			cout << maxneg * minpos << '\n';
		else
			cout << ans << '\n';
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
