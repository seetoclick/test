#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int t, n;

void solve() {
	string s;
	cin >> s;
	n = s.size();
	for (int i = 0; 2 * i + 1 < n; ++i) {
		cout << s[2 * i + 1] << s[2 * i];
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}
