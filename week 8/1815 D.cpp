#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const LL P = 998244353;
LL t, n, m;
map<LL, LL> F, G;

LL g(LL x) {
	if (x == 0)
		return 1;
	if (G[x])
		return G[x];
	if (x % 2 == 1) {
		G[x] = g((x - 1) / 2);
		return G[x];
	} else {
		G[x] = (g(x / 2) + g(x / 2 - 1)) % P;
		return G[x];
	}
}

LL f(LL x) {
	if (x == 0)
		return 0;
	if (F[x])
		return F[x];
	if (x % 2 == 1) {
		F[x] = (2 * f((x - 1) / 2) + g(x)) % P;
		return F[x];
	} else {
		F[x] = 2 * (f(x / 2) + f(x / 2 - 1)) % P;
		return F[x];
	}
}



void solve() {
	cin >> n >> m;
	if (m == 1)
		cout << n % P << '\n';
	else if (m >= 3) {
		if (n % 2 == 0) {
			LL num = n / 2 % P;
			cout << num * (num + 1) % P << '\n';
		} else {
			LL num = (n + 1) / 2 % P;
			cout << num * num % P << '\n';
		}
	} else {
		cout << f(n) << '\n';
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
