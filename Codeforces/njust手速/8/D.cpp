#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll P = 1e9 + 7;
ll t = 1, n;
ll a[2000], fac[2000], inv[1500];

ll qpow(ll a, ll n) {
	ll rel = 1;
	while (n) {
		if (n % 2 == 1) {
			rel = (rel * a) % P;
		}
		a = (a * a) % P;
		n /= 2;
	}
	return rel;
}

void init() {
	fac[1] = 1;
	for (int i = 2; i <= 1000; ++i) {
		fac[i] = (fac[i - 1] * i) % P;
	}
	
	inv[1000] = qpow(fac[1000], P - 2); 
	for (int i = 999; i >= 1; --i) {
		inv[i] = ((i + 1) * inv[i + 1]) % P;
	}
}

void solve() {
	ll k;
	cin >> k;
	ll n = 0;
	for (int i = 1; i <= k; ++i) {
		cin >> a[i];
		n += a[i];
	}
	a[1]++;
	
	ll ans = fac[n - (k - 1)];
	for (int i = 1; i <= k; i++) {
		ans = (ans * inv[a[i] - 1]) % P;
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	//cin >> t;
	init();
	while (t--) {
		solve();
	}
	
	return 0;
}
