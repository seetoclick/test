#include <iostream>
#include <vector>
using namespace std;
using LL = long long;

LL t, n, l, r;
const LL P = 1e9 + 7;
int fa[200009], siz[200009];

int find(int x) {
	if (x == fa[x])
		return fa[x];
	else {
		return fa[x] = find(fa[x]); 
	}
}

void merge(int x, int y) {
	int fx = find(x), fy = find(y);//cout << size[fx] << ' ' << size[fy] << '\n';
	if (fx == fy)
		return;
	if (siz[fx] < siz[fy]) {
		siz[fy] += siz[fx];
		fa[fx] = fy;		
	} else {
		siz[fx] += siz[fy];
		fa[fy] = fx;
	}
}

void solve() {
	cin >> n >> l >> r;
//	for (int i = 1; i <= n; ++i) {
//		int u, v;
//		cin >> u >> v;
//		G[u].push_back(v);
//		G[v].push_back(u);
//	}
//	vector<int> con;
	for (int i = 1; i <= n; ++i)
		fa[i] = i, siz[i] = 1;

	for (int i = 1; i <= n; ++i) {
		int u, v;
		cin >> u >> v;
		merge(u, v);
	}
	//vector<int> sg;
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (fa[i] == i) {
			ans ^= (siz[i] % (r - l + 1)) / l;
		}
	}
	if (!ans)
		cout << "Bob";
	else 
		cout << "Alice";
	//cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}
