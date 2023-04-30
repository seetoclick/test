#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, a[15][15], c[15];
int ans = 0, ed = ((1 << (n + 1)) - 2);

int dfs(int pos, int s) {
	//cout << pos << ' ' << s << '\n';
	if (pos > m) {
		if (s == ed)
			return 1;
		return 0;
	}

	int rel = 0;
	int s1 = 0, s2 = 0;
	for (int i = 1; i <= c[pos]; i++) {
		s1 |= (1 << a[pos][i]);
	}
	rel = dfs(pos + 1, s | s1) + dfs(pos + 1, s | s2);
	return rel;
} 

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> c[i];
		for (int j = 1; j <= c[i]; ++j) {
			cin >> a[i][j];
		}
	}
	ed = ((1 << (n + 1)) - 2);
	//cout << ed << "\n\n\n";
	cout << dfs(1, 0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}
