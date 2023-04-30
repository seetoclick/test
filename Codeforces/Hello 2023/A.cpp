#include <bits/stdc++.h>
using namespace std;

int t, n, L[100009];
string s;

void solve() {
	cin >> n >> s;
	int L = 0, R = 0;
	for (auto &c: s) {
		if (c == 'L') L++;
	}
	if (L == 0 || L == n) {
		cout << "-1\n";
		return;
	}
	
	L = -1, R = n;
	while (s[L + 1] == 'L') L++;
	while (s[R - 1] == 'R') R--;
	if (R - L == 1) {
		cout << L << '\n';
	}
	else {
		cout << "0\n";
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
