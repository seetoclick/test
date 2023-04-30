#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t = 1, n;
const int N = 1e5;
struct Edge {
	int to, nxt;
} e[N * 2 + 39];
int cnt = -1, num = 0, head[N + 19], ans[2 * N + 39];

void add(int u, int v) {
	++cnt;
	e[cnt].to = v;
	e[cnt].nxt = head[u];
	head[u] = cnt;
}

void dfs(int r, int fa, int c) {
	int d = 1;
	for (int i = head[r]; i != -1; i = e[i].nxt) {
		if (e[i].to == fa)
			continue;
		if (d == c)
			d++;
		//cout << "节点" << e[i].to << " 所在边颜色为 " << d <<  " 其父边颜色为" << ans[fcnt] << ' ' << ans[fcnt ^ 1] << '\n'; 
		ans[i] = d;
		num = max(num, d);
		dfs(e[i].to, r, d);
		d++;
	}
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n + 5; ++i)
		head[i] = -1;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		add(u, v);
		add(v, u);
	}
	
	dfs(1, 0, 0);
	
	cout << num << '\n';
	for (int i = 0; i < 2 * (n - 1); i += 2) {
		if (ans[i])
			cout << ans[i];
		else
			cout << ans[i ^ 1];
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	//cin >> t;
	while (t--) {
		solve();
	}
	
	return 0;
}
