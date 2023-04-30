#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n, k;
const LL P = 1e9 + 7;
const int inf = 0x3f3f3f3f;
string s;

void solve() {
	cin >> n >> s;
	int ans = inf;
	int l = -1, r = -1;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		if (s[i] == 'R')
			r = x;
		else if (s[i] == 'L' && r != -1) {
			l = x;
			ans = min(ans, (l - r) / 2);
		}
	}
	
	if (ans == inf)
		cout << "-1\n";
	else
		cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
//	cin >> t;
//	while (t--) {
		solve();
//	}
	
	return 0;
}
