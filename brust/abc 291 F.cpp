#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int n, m, s;
const int inf = 2000000000;
const int N = 1e5;

typedef pair<int, int> Pair;
priority_queue<Pair, vector<Pair>, greater<Pair> > Q;
vector<vector<int>> G_1(N + 3), G_2(N + 3);
vector<int> dist_1(N + 3), dist_2(N + 3), vis(N + 3);

void Dij(int s, vector<int>& dist, vector<vector<int>>& G) {
	for (int i = 1; i <= n; ++i)
		dist[i] = inf;
	dist[s] = 0;
	Q.push(make_pair(0, s));
	while (!Q.empty()) {
		int p = Q.top().second;
		Q.pop();
		vis[p] = 1;//cout << p << '\n';
		for (auto to : G[p]) {
			dist[to] = min(dist[to], dist[p] + 1);
			if (!vis[to])
				Q.push(make_pair(dist[to], to));
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			if (s[j] == '1') {
				G_1[i].push_back(i + j + 1);
				G_2[i + j + 1].push_back(i);				
			}
		}
	}
	
	Dij(1, dist_1, G_1);
	vis.assign(vis.size(), 0);
	Dij(n, dist_2, G_2);

	for (int k = 2; k <= n - 1; ++k) {
		LL ans = inf;		
		for (int i = k - 1; i >= 1 && i >= k - m; i--) {
			for (auto to : G_1[i]) {
				if (to <= k) continue;
				ans = min(ans, dist_1[i] + 1LL + dist_2[to]);
			}
		}
		if (ans >= inf)
			ans = -1;
		cout << ans << ' ';
	}
	
	return 0;
}
