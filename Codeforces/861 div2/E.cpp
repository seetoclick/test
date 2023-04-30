#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n;
const LL P = 1e9 + 7;

int cal(LL x) {
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
	LL l, r;
	cin >> l >> r;
	cout << cal(1256156) << '\n';
//	if (r - l >= 1000) {
//		for (LL i = l; i <= r; ++i) {
//			if (cal(i) == 0) {
//				cout << i << '\n';
//				return;
//			}
//		}
//	} else {
//		LL minindex = l;
//		for (LL i = l; i <= r; ++i) {
//			if (cal(minindex) > cal(i))
//				minindex = i;
//		}
//		cout << minindex << '\n';
//	}
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
