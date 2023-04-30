#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n;
const LL P = 1e9 + 7;
int a[1024];

void solve() {
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		ans ^= a[i];
	}
	
	if (n % 2 == 0) {
		if (ans == 0)
			cout << "0\n";
		else
			cout << "-1\n";
	} else {
		cout << ans << '\n';
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
