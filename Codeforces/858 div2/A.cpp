#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n;
const LL P = 1e9 + 7;


void solve() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int y = a + d - b - c, x = d - b;
	if (x >= 0 && y >= 0) {
		cout << x + y << '\n';
	} else {
		cout << "-1\n";
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
