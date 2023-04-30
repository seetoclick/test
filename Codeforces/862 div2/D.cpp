#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL n;
const LL P = 1e9 + 7;
LL h[100009], H;
vector<int> G[100009];
vector<int> ans(100009);

void dfs(int r, int fa) {
	for (auto& p : G[r]) {
		if (p == fa)
			continue;
		h[p] = h[r] + 1;
		H = max(H, h[p]);
		dfs(p, r);
	}
}


void solve() {
	cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	dfs(1, 0);
	for (int k = 1; k <= n; ++k) {
		if (k <= H)
			cout << "1 ";
		else if (k > H + H)
			cout << n << ' ';
		else
			cout << min(k - H - 1, H) + 1 << ' ';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
	
	return 0;
}
