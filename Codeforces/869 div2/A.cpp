#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n, k;
const LL P = 1e9 + 7;

char s[152][152];

void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= k; ++j)
			cin >> s[i][j];
	
	
	bool vis[150] = {0};
	for (int i = 1; i <= k; ++i) {
		int yes = 0, no = 0;
		for (int j = 1; j <= n; ++j) {
			if (vis[j])
				continue;
			if (s[j][i] == '+')
				yes++;
			else 
				no++;
		}
		if (s[1][i] == '+') {
			for (int j = 2; j <= n; ++j)
				if (s[j][i] == '-')
					vis[j] = 1;
		} else if (s[1][i] == '-'){
			for (int j = 2; j <= n; ++j)
				if (s[j][i] == '+')
					vis[j] = 1;			
		} 
	}
	
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (!vis[i])
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
