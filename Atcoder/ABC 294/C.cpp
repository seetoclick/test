#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 1e5;
int t, n, m, a[N + 5], b[N + 5], ansa[N + 5], ansb[N + 5];

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= m; ++i)
		cin >> b[i];
	int i = 1, j = 1;
	int pos = 0;
	while (i <= n && j <= m) {
		if (a[i] < b[j]) {
			ansa[i] = ++pos;
			i++;
		} else {
			ansb[j] = ++pos;
			j++;
		}
	}
	while (i <= n) {
		ansa[i] = ++pos;
		i++;
	}
	while (j <= m) {
		ansb[j] = ++pos;
		j++;
	}
	
	for (int i = 1; i <= n; ++i)
		cout << ansa[i] << ' ';
	cout << '\n';
	for (int j = 1; j <= m; ++j)
		cout << ansb[j] << ' ';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}
