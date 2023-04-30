#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t = 1, n;

void solve() {
	ll a, b;
	cin >> n >> a >> b;
	if (n * a > b)
		cout << b;
	else
		cout << n * a;
	
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
