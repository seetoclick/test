#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 2e5;
int n, m;

void solve() {
	cin >> n >> m;
	vector<int> e[n + 5], d(n + 5, 0);	
	for (int i = 1; i <= m; ++i) {
		int x, y;
		cin >> x >> y;
		e[x].push_back(y);
		d[y]++;
	}	

	int st = 0, cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (d[i] == 0) {
			st = i;
			cnt++;
		}
	}
	if (cnt != 1) {
		cout << "No";
		return;
	}
	
	vector<int> f(n + 1, 0);
	queue<int> q;
	int ed = 0;
	q.push(st);
	f[st] = 1;
	while (!q.empty()) {
		int p = q.front();
		q.pop();//cout << p << '\n';
		for (auto u : e[p]) {
			d[u]--;
			if (d[u])
				continue;
			if (f[u] >= f[p] + 1)
				continue;
			f[u] = f[p] + 1;
			if (f[u] == n) {
				ed = u;
			}
			q.push(u);
		}
	}
	
	if (!ed) {
		cout << "No";
	} else {
		cout << "Yes\n";
		for (int i = 1; i <= n; ++i)
			cout << f[i] << ' ';
	}
	
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
	
	return 0;
}
