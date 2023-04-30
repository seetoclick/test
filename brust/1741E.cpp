#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 2e5 + 5;
LL t, n, s;
int a[N], ok[N];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		ok[i] = 0;
	}

	ok[0] = 1;
	for (int i = 1; i <= n; ++i) {
		if (i - a[i] >= 1)
			ok[i] = ok[i - a[i] - 1] | ok[i]; 
		if (i + a[i] <= n)
			ok[i + a[i]] = ok[i - 1] | ok[i + a[i]];
	}
	
	if (ok[n])
		cout << "YES\n";
	else
		cout << "NO\n";
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
