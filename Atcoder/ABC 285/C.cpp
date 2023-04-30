#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;

void solve() {
	string s;
	cin >> s;
	
	ll ans = 0;
	for (int i = 0; i < (int)s.size(); ++i) {
		int d = s[i] - 'A' + 1;
		ans = 26 * ans + d;
	}
	
	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}
