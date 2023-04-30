#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n, k, c;
const LL P = 1e9 + 7;

void solve() {
	cin >> n >> k >> c;
	vector<vector<int>> G(n + 1);
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	int maxID = 0;
	vector<int> dep(n + 1);
	dep[1] = 0;
	auto dfs = [&](int x, int fa) {
		function<void(int, int)> f;
		f = [&](int x, int fa) {
			if (dep[x] > dep[maxID])
				maxID = x;
			for (auto &p : G[x]) {
				if (p != fa) {
				dep[p] = dep[x] + 1;					
					f(p, x);
				}
			}			
		};
		f(x, fa);
	};
	dfs(1, 0);
	//cout << maxID << " ! " ;
	vector<int> dist(n + 1);
	dist[maxID] = 0;
	auto dfs2 = [&](int x, int fa) {
		function<void(int, int)> f;
		f = [&](int x, int fa) {
			//cout << x << ' ' << dist[x] << '\n';
			for (auto &p : G[x]) {
				if (p != fa) {
					dist[p] = dist[x] + 1;					
					f(p, x);
				}
			}			
		};
		f(x, fa);
	};
	dfs2(maxID, 0);
//	cout << maxID << '\n';
//	for (int i = 1; i <= n; ++i)
//		cout << dist[i] << ' ';
//	cout << '\n';
	LL ans = 0;	
	for (int i = 1; i <= n; ++i)
		ans = max(ans, dist[i] * k - dep[i] * c);
	cout << ans << '\n';
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
