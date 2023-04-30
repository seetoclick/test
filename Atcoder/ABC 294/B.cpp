#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int t, n;

void solve() {
	int h, w;
	cin >> h >> w;
	for (int i = 1; i <= h; ++i) {
		for (int j = 1; j <= w; ++j) {
			int x;
			cin >> x;
			if (x == 0)
				cout << ".";
			else {
				cout << char(x - 1 + 'A');
			}
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}
