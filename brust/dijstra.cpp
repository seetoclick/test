#include <bits/stdc++.h>
using namespace std;

int n, m, s;
const int inf = 2000000000;
const int N = 1e5;

typedef pair<int, int> Pair;
priority_queue<Pair, vector<Pair>, greater<Pair> > Q;
vector<Pair> G[N + 3];
vector<int> dist(N + 3), vis(N + 3);

void Dij(int s) {
	for (int i = 1; i <= n; ++i)
		dist[i] = inf;
	dist[s] = 0;
	Q.push(make_pair(0, s));
	while (!Q.empty()) {
		int p = Q.top().second;
		Q.pop();
		if (vis[p])
			continue;
		vis[p] = 1;
		for (auto e : G[p]) {
			int to = e.first, w = e.second;
			dist[to] = min(dist[to], dist[p] + w);
			if (!vis[to])
				Q.push(make_pair(dist[to], to));
		}
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		G[u].push_back({v, w});
	}
	
	Dij(s);
	
	for (int i = 1; i <= n; ++i) {
		printf("%d ", dist[i]);
	}
	return 0;
}
