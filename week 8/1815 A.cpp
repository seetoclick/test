#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int t, n;

void solve() {
	cin >> n;
	vector<int> a(n + 1, 0), b(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		b[i] = a[i] - a[i - 1];
	}
	
	if (n % 2 == 1) {
		cout << "YES\n";
	} else {
		LL s = 0;
		for (int i = n; i >= 1; i -= 2)
			s += b[i];
		if (s >= 0 || s >= b[1])
			cout << "YES\n";
		else
			cout << "NO\n";		
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
