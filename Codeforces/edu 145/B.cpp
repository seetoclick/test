#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n;
const LL P = 1e9 + 7;


void solve() {
	cin >> n;

	LL L = 0, R = 1e9;
	while (L < R) {
		if (R - L == 1) {
			if (L * L <= n && R * R > n) {
				R = L;
				break;
			} else {
				L = R;
				break;
			}
		}
		
		LL m = (L + R) / 2;
		if (m * m == n) {
			L = R = m;
		} else if (m * m > n) {
			R = m - 1;
		} else if (m * m < n) {
			L = m;
		} 
	}
	
	if (L * L == n)
		cout << L - 1;
	else
		cout << L;
	cout << '\n';
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
