#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const LL P = 998244353;
const int N = 1000000;
int h, w, k;
LL fac[N+ 4], invFac[N+ 4];

LL qpow(LL a, LL n) {
	LL ans = 1;
	while (n) {
		if (n % 2 == 1)
			ans = (ans * a) % P;
		a = (a * a) % P;
		n /= 2;
	}
	return ans;
}

LL C(int n, int m) {
	if (n < m)
		return 0;
	if (n < 0 || m < 0)
		return 0;
	return fac[n] * invFac[m] % P * invFac[n - m] % P;
}

void init() {
	fac[0] = 1;
	for (int i = 1; i <= N; ++i)
		fac[i] = (i * fac[i - 1]) % P;
	invFac[N] = qpow(fac[N], P - 2);
	for (int i = N - 1; i >= 0; --i)
		invFac[i] = (i + 1) * invFac[i + 1] % P;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	init();
	cin >> h >> w >> k;
	LL ans = 0;
	for (int i = 1; i <= h; ++i) {
		for (int j = 1; j <= w; ++j) {
			LL num = C(i * j, k);//cout << i << ' ' << j << ' ' << num << ' ';
			if (i * j < k)
				continue;
			num = 10 * P + num - 2 * C(i * (j - 1), k) - 2 * C((i - 1) * j, k) + 4 * C((i - 1) * (j - 1), k) + C(i * (j - 2), k) + C((i - 2) * j, k) - 2 * C((i - 1) * (j - 2), k) - 2 * C((i - 2) * (j - 1), k);
			if (i >= 2 && j >= 2)
				num = num + C((i - 2) * (j - 2), k);
			num = (num + P) % P;//cout << C((i - 2) * (j - 2), k) << '\n';
//			if (num < 0)
//				cout << i << ' ' << j << '\n';
			ans = (i * j % P * (h - i + 1) % P * (w - j + 1) % P * num % P + ans) % P;
		}
	}
	cout << ans * qpow(C(h * w, k), P - 2) % P;
	return 0;
}
