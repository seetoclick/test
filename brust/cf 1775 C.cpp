#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int t;

void solve() {
	LL n, x;
	cin >> n >> x;
	
	if (n == x) {
		cout << n << '\n';
		return;
	}
	
	vector<int> dn, dx;
	while (n) {
		dn.push_back(n % 2);
		n /= 2;
	}
	while (x) {
		dx.push_back(x % 2);
		x /= 2;
	}
	
	if (dn.size() != dx.size()) {
		if (dx.size() == 0) {
			cout << (1LL << dn.size()) << '\n';
		} else {
			cout << "-1\n";
		}
		return;
	}
	
	int len = dn.size(), dif = -1;
	len--;
	for (int i = len; i >= 0; --i) {
		if (dn[i] == 0 && dx[i] == 1) {
			cout << "-1\n";
			return;
		}
		if (dn[i] != dx[i] && dif == -1)
			dif = i;
	}
	if (dn[dif + 1] != 0) {
		cout << "-1\n";
		return;
	}
	for (int i = dif - 1; i >= 0; --i) {
		if (dx[i] != 0) {
			cout << "-1\n";
			return;
		}
	}
	
	dx[dif + 1] = 1;
	LL ans = 0;
	for (int i = len; i >= 0; --i) {
		ans = 2 * ans + dx[i];
		//cout << dx[i] << ' ';
	}
	cout << ans << '\n';
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
