#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t = 1, n;

void solve() {
	cin >> n;
	while (n) {
		int r = n % 10;
		if (r == 7) {
			cout << "Yes\n";
			return;
		}
		n /= 10;
	}
	cout << "No\n";
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
