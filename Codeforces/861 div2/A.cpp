#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n;
const LL P = 1e9 + 7;

int cal(int x) {
	int mi = 11, ma = 0;
	while (x) {
		int r = x % 10;
		mi = min(mi, r);
		ma = max(ma, r);
		x /= 10;
	}
	return ma - mi;
}

void solve() {
	int l, r;
	cin >> l >> r;
	if (r - l >= 20) {
		for (int i = l; i <= r; ++i) {
			if (cal(i) == 9) {
				cout << i << '\n';
				return;
			}
		}
	} else {
		int minindex = l;
		for (int i = l; i <= r; ++i) {
			if (cal(minindex) < cal(i))
				minindex = i;
		}
		cout << minindex << '\n';
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
