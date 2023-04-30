#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n;
string s;
const LL P = 1e9 + 7;

void solve() {
	cin >> n >> s;
	int cnt = n - 1;
	for (int i = 0; i + 2 < n; ++i) {
		if (s[i] == s[i + 2])
			cnt--;
	}
	cout << cnt << '\n';
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
