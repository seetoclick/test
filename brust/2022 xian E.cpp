#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int t;
int a[50], b[50], cnta = 0, cntb = 0;
int ans = 0;

int dfs(int pos, int limit1, int limit2, int lead, int res) {
	//cout << pos << ' ' << res << '\n';
	if (pos <= 0) {
		ans = max(ans, res);
		return ans;
	} 
	
	int sup = 2, inf = 0;
	if (limit1) {
		inf = max(inf, a[pos]);
	}
	if (limit2) {
		sup = min(sup, b[pos]);
	}
	if (!limit1 && !limit2) {
		return dfs(0, 0, 0, 0, res + 3 * pos);
	}
	for (int i = inf; i <= sup; ++i) {
		if (i == 0)
			ans = max(ans, dfs(pos - 1, limit1 & (i == a[pos]), limit2 & (i == b[pos]), 1, res)); 
		else
			ans = max(ans, dfs(pos - 1, limit1 & (i == a[pos]), limit2 & (i == b[pos]), 0, res + i + 1));
	}
	return ans;
}

void solve() {
	LL l, r;
	cin >> l >> r;
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	
	cnta = 0, cntb = 0;
	while (l) {
		a[++cnta] = l % 3;
		l /= 3;
	}
	while (r) {
		b[++cntb] = r % 3;
		r /= 3;
	}
	
	ans = 0;
	cout << dfs(cntb, 1, 1, 1, 0) << '\n';
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
