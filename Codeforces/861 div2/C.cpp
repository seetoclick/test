#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n, S = 0, pow10[70];
const LL P = 1e9 + 7;

int a[50], b[50], cnta = 0, cntb = 0;
int ans = 0;

void dfs(int pos, int limit1, int limit2, int mx, int mi, LL sta) {
	//cout << pos << ' ' << sta <<  '\n';
	if (pos <= 0) {
		if (ans > mx - mi) {
			ans = mx - mi;
			S = sta;
		}
		return;
	} 
	
	int sup = 9, inf = 0;
	if (limit1) {
		inf = max(inf, a[pos]);
	}
	if (limit2) {
		sup = min(sup, b[pos]);
	}//cout << inf << ' ' << sup << '\n';
	if (!limit1 && !limit2) {
		
		return dfs(0, 0, 0, mx, mi, sta);
	}
	if (mx == 0) {
		mx = -1,
		mi = 10;
	}
	for (int i = inf; i <= sup; ++i) {
		dfs(pos - 1, limit1 & (i == a[pos]), limit2 & (i == b[pos]), max(mx, i), min(mi, i), 10 * sta + i); 
	}
}

void solve() {
	LL l, r, tmpl;
	cin >> l >> r;
	tmpl = l;
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	
	cnta = 0, cntb = 0;
	while (l) {
		a[++cnta] = l % 10;
		l /= 10;
	}
	while (r) {
		b[++cntb] = r % 10;
		r /= 10;
	}
	
	ans = 10;
	dfs(cntb, 1, 1, -1, 10, 0);
	int rem = S % 10;
	while (S < tmpl) {
		S = 10 * S + rem;
	}
	cout << S << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
//	pow10[0] = 1;
//	for (int i = 1; i <= 18; ++i)
//		pow10[i] = 10 * pow10[i - 1];
	cin >> t;
	while (t--) {
		solve();
	}
	
	return 0;
}
