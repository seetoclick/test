#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int t;

void solve() {
	string s;
	cin >> s;
	char ss[220];
	int cnt = 0;	
	int n = s.size();
	if (n == 1 && s[0] == '^') {
		cout << "1\n";
		return;
	}
	
	for (int i = 0; i < n; ++i) {
		if (s[i] == '^')
			ss[++cnt] = s[i];
		else {
			if (i == 0) {
				ss[++cnt] = '^';
			} 
			if (s[i + 1] != '^') {
				ss[++cnt] = '_';
				ss[++cnt] = '^';
			} else {
				ss[++cnt] = '_';
			}
		}
	}
//	for (int i = 1; i <= cnt; ++i)
//		cout << ss[i];
	//cout << '\n' << cnt << '\n';
	cout << cnt - n << '\n';
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
