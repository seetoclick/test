#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, a[150];
int nxt[150];

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> a[i];
		nxt[a[i]] = a[i] + 1;
	}
	
	int l = 1, r;
	for (int i = 1; i <= n; ++i) {
		if (!nxt[i]) {
			cout << i << ' ';
		} else {
			l = i, r = i;
			while (nxt[r])
				r = nxt[r];
			for (int j = r; j >= l; --j) {
				cout << j << ' ';
			}
			i = r;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}
