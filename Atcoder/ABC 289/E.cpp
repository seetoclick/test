#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2500;
int t, n, m;
vector<int> color(N), nxt[N];

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		nxt[u].push_back(v);
		nxt[v].push_back(u);
	}
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
