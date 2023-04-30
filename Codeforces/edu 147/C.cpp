#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t;
const LL P = 1e9 + 7;
string s;

void solve() {
	cin >> s;
	int n = s.size();
	vector<vector<int>> dic(26);
	vector<int> nxt(n, 0);
	for (int i = 0; i < n; ++i) {
		dic[s[i] - 'a'].push_back(i);
	}

	int ans = 200009;
	for (int i = 0; i < 26; ++i) {
		if (dic[i].size() == 0)
			continue;
		char c = 'a' + i;//cout << c << '\n';
		int cnt = 0, maxcnt = 0;
		for (int j = 0; j < n; ++j) {
			if (s[j] == c) 
				cnt = 0;				
			else
				cnt++;
//			if (i == 0)
//				cout << cnt << '\n';
			maxcnt = max(maxcnt, cnt);
		}
		ans = min(ans, maxcnt);
	}
	//cout << ans << ' ';
	int cnt = 0;
	while (ans != 0) {
		int choose = (ans + 1) / 2;
		ans -= choose;
		cnt++;
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
