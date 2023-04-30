#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t = 1, n;

void solve() {
	int A, B;
	cin >> A >> B;
	
	double l1 = 12.5 * A, r1 = 12.5 * (A + 1);
	double l2 = 10.0 * B, r2 = 10.0  * (B + 1);
	double l = max(l1, l2), r = min(r1, r2);
	int L = ceil(l), R = int(r) == r ? (int) r - 1 : int(r);
	if (L > R)
		cout << "-1";
	else
		cout << L;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	//cin >> t;
	while (t--) {
		solve();
	}
	
	return 0;
}
