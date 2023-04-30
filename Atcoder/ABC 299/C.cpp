#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int t, n;
string s;

void solve() {
	cin >> n >> s;
	int len = s.size();
	int cnt = 0, maxcnt = 0;
	for (int i = 0; i < len; ++i) {
		if (s[i] != 'o') {
			maxcnt = max(maxcnt, cnt);
			cnt = 0;
		} else {
			cnt++;
		}
	}
	maxcnt = max(maxcnt, cnt);
	
	if (maxcnt == 0 || maxcnt == len)
		cout << "-1";
	else
		cout << maxcnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}
