#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string s;
ll t = 1, n, r[4004], g[4004], b[4004];

void solve() {
	cin >> n >> s;
	if (s[0] == 'R') r[0] = 1;
	else if (s[0] == 'G') g[0] = 1;
	else b[0] = 1;
	
	for (int i = 1; i < n; ++i) {
		r[i] = r[i - 1];
		b[i] = b[i - 1];
		g[i] = g[i - 1];
		if (s[i] == 'R') {
			r[i]++;
		}
		else if (s[i] == 'G') {
			g[i]++;
		}
		else {
			b[i]++;
		}
	}
	
	ll ans = 0;
	for (int i = 2; i < n; ++i) {
		if (s[i] == 'R')
			ans += g[i] * b[i];
		else if (s[i] == 'G')
			ans += r[i] * b[i];
		else 
			ans += r[i] * g[i];
		//cout << ans << '\n';
	}
	
	for (int i = 0; i < n; ++i)
		for (int d = 1; i + 2 * d <= n - 1; ++d)
			if (s[i] != s[i + d] && s[i] != s[i + 2 * d] && s[i + d] != s[i + 2 * d])
				ans--;
	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	//cin >> t;
	while (t--) {
		solve();
	}
	
	return 0;
}
