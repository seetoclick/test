#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n;
const LL P = 1e9 + 7;
const int N = 2e5;

LL icm(LL a, LL b) {
	return a / __gcd(a, b) * b;
}

void solve() {
	cin >> n;
	vector<LL> a(n + 1), b(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> a[i] >> b[i];		
	
	int cnt = 0;
	LL g = 0, l = 1;	
	for (int i = 1; i <= n; ++i) {
		g = __gcd(g, a[i] * b[i]);
		l = icm(l, b[i]);
		if (g % l != 0) {
			cnt++;
			g = a[i] * b[i], l = b[i];
		}
	}
	
	cout << cnt + 1 << '\n';
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
