#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int a, b, c, t;
const ll P = 998244353;
const int N = 100005;

ll f[N], g[N], h[N];

ll qpow(ll a, ll n) {
	ll rel = 1;
	while (n) {
		if (n % 2 == 1)
			rel = (rel * a) % P;
		a = (a * a) % P;
		n /= 2;
	}
	return rel;
}

void solve() {
	cin >> a >> b >> c >> t;
	
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}
