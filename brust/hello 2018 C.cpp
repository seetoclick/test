#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL n, L, c[50], pow2[50];
double ave[50];
map<int, LL> f;

LL dp(int V) {
	if (V <= 0)
		return 0;
	if (f[V])
		return f[V];
	
	LL ans = 1e18;
	for (int i = 1; i <= n; ++i) {
		ans = min(ans, dp(V - pow2[i]) + c[i]);
	}
	f[V] = ans;
	return ans;
}

void solve() {
	cin >> n >> L;
	LL preCost = 0, index = 1;
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
		pow2[i] = (1 << (i - 1));
		ave[i] = 1.0 * c[i] / pow2[i];
		if (ave[i] < ave[index])
			index = i;
	}
	
	preCost = (L / pow2[index]) * c[index];
	L -= pow2[index] * (L / pow2[index]);
	cout << preCost + dp(L);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}
