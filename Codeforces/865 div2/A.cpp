#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n;
const LL P = 1e9 + 7;


void solve() {
	int a, b;
	cin >> a >> b;
	if (a == 1 && b == 1) {
		cout << "1\n1 1\n";
	}
	cout << "2\n";
	LL x = 1;
	cout << a - x << ' ' << 1 << '\n';
	cout << a << ' ' << b << '\n';
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
