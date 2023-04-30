#include <bits/stdc++.h>
using namespace std;
using LL = long long;

struct Edge {
	int to, w;
};

LL t, n, m;


//
//void solve() {
//	cin >> n >> m;
//	vector<vector<Edge>> e(n + 1);
//	for (int i = 1; i <= n; ++i) {
//		int u, v;
//		string s;
//		cin >> u >> v >> s;
//		if (s == "imposter") {
//			e[u].push_back({v, 0});
//		} else {
//			e[v].push_back({v, 1});
//		}
//	}
//	
//	
//}
void solve() {
	cin >> n;
	LL s = 0;
	vector<int> a(n);
	map<int, int> mp;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		s += a[i];
		mp[a[i]]++;
	}
	
	if (2 * s % n != 0) {
		cout << "0\n";
		return;
	}
	
	LL ans = 0;
	s = 2 * s / n;
	for (int i = 0; i < n; ++i) {
		ans += mp[s - a[i]];
		if (2 * a[i] == s)
			ans--;
	}
	cout << ans / 2 << '\n';
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
