#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL a, x, m;

LL qpow(LL a, LL n) {
	LL ans = 1;
	while (n) {
		if (n % 2 == 1) {
			ans = (ans * a) % m;			
		}
		a = (a * a) % m;
		n /= 2;
	}
	return ans;
}

void solve() {
	cin >> a >> x >> m;
	x--;
	LL N = 1e6;
	if (x <= N * 2) {
		LL t = 1, s = 1;
		for (LL i = 1; i <= x; ++i) {
			t = (t * a) % m;	//t = a^i		
			s = (s + t) % m;//cout << t << '\n';
		}
		cout << s % m;
		return;
	}
	
	LL k = (x + 1) / N;
	LL s1 = 1, s2 = 1, t = 1, res = 0;
	for (int i = 1; i < N; ++i) {
		t = (t * a) % m;
		s1 = (s1 + t) % m;
	}
	
	LL aa = qpow(a, N);
	t = 1;
	for (int i = 1; i < k; ++i) {
		t = (t * aa) % m;
		s2 = (s2 + t) % m;
	}
	
	t = qpow(a, k * N - 1);
	k = k * N;
	for (; k <= x; ++k) {
		t = (t * a) % m;
		res = (res + t) % m;
	}
	
	cout << (s1 * s2 % m + res) % m;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}
