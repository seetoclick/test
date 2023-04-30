#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int n;
const LL P = 998244353;

LL qpow(LL a, LL n) {
	LL rel = 1;
	while (n) {
		if (n & 1) {
			rel = (rel * a) % P;
		}
		a = (a * a) % P;
		n /= 2;
	}
	return rel;
}
int w[300009];
LL fac[100009];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> w[i];
	}
	fac[0] = 1;
	for (int i = 1; i <= n / 3; ++i)
		fac[i] = (fac[i - 1] * i) % P;
	
	int cnt2 = 0, cnt3 = 0, L = 1, R = 3;
	for (int i = 1; i <= n / 3; ++i) {
		sort(w + L, w + R + 1);
		if (w[L] == w[L + 1] && w[L + 1] == w[L + 2])
			cnt3++;
		if (w[L] == w[L + 1] && w[L + 1] != w[L + 2])
			cnt2++;
		L += 3, R += 3;
	}
	
	LL ans = qpow(2, cnt2) * qpow(3, cnt3) % P * fac[n / 3] % P * qpow(fac[n / 6], P - 2) % P * qpow(fac[n / 6], P - 2) % P;
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}
