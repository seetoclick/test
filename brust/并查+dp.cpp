#include <bits/stdc++.h>
using namespace std;

int n, m, W, cnt, fa[40009], vis[40009], dp[40009], cost[40009], w[40009], a[40009], b[40009];

int find(int x) {
	return x == fa[x] ? x : find(fa[x]);
}

void merge(int a, int b) {
	fa[find(b)] = find(a);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m >> W;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> b[i];
		fa[i] = i;
	}
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		merge(u, v);
	}
	
	for (int i = 1; i <= n; ++i) {
		if (vis[fa[i]])
			continue;
		vis[fa[i]] = 1;
		
	}
}
