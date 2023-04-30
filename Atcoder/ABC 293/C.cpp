#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int h, w;
int a[15][15];

map<int, int> mp;
int ans = 0;
void dfs(int i, int j) {cout << i << ' ' << j << '\n';
	if (mp[a[i][j]] > 0)
		return;
	if (i == h && j == w) {
		ans++;
		return;
	}	
	
	mp[a[i][j]]++;
	if (i + 1 <= h) {
		dfs(i + 1, j);
		mp[a[i][j]] = 0;
	}
	if (j + 1 <= w) {
		dfs(i, j + 1);
		mp[a[i][j]] = 0;
	}

}

void solve() {
	cin >> h >> w;
	for (int i = 1; i <= h; ++i) {
		for (int j = 1; j <= w; ++j) {
			cin >> a[i][j];
		}
	}
	
	dfs(1, 1);
	
	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}
