#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

int t, n, m, k, cnt;
int p[2020], d[2020], color[2020];
vector<int> G[2020]; 

void bfs1(int st, int D) { 
	queue<pair<int, int>> q;
	q.push({st, 0});
	int vis[2020] = {0};

	while (!q.empty()) {
		PII p = q.front();
		q.pop();
		int id = p.first, dis = p.second;	
		vis[id] = 1;
		if (dis == D)
			continue;
		color[id] = 0;
		for (auto &x : G[id]) {
			if (vis[x])
				continue;
			q.push({x, dis + 1});
		}
	}
}

bool bfs2(int st, int D) {
	queue<pair<int, int>> q;
	q.push({st, 0});
	int vis[2020] = {0};
	
	while (!q.empty()) {
		PII p = q.front();
		q.pop();
		int id = p.first, dis = p.second;	
		vis[id] = 1;
		if (dis == D) {//cout << D << ' ' << color[id] << '\n';
			if (color[id] == 1)
				return 1;
			else
				continue;
		}
			
		for (auto &x : G[id]) {
			if (vis[x])
				continue;
			q.push({x, dis + 1});
		}
	}	
	return 0;
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	cin >> k;
	for (int i = 1; i <= n; ++i)
		color[i] = 1;
	for (int i = 1; i <= k; ++i) {
		cin >> p[i] >> d[p[i]];
	}

	int cnt = 0;
	cnt = n;
	for (int i = 1; i <= k; ++i) {
		bfs1(p[i], d[p[i]]);	
			cnt++;
	}
	for (int i = 1; i <= k; ++i) {
		if (!bfs2(p[i], d[p[i]])) {
			cout << "No";
			return;
		}
	}	
	
	cout << "Yes\n";
	for (int i = 1; i <= n; ++i)
		cout << color[i];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}
