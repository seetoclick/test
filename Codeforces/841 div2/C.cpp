#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int t, n;
int square[1000], num;

void solve() {
	cin >> n;
	vector<int> cnt(2 * n + 10, 0), a(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	int s = 0, bad = 0;
	for (int i = 1; i <= n; ++i) {
		s ^= a[i];	
		cnt[s]++;
		for (int j = 0; j < num && j <= sqrt(2 * n + 10); ++j) {	//equivpment to xor[i] ^ j^2 = xor[?]
			int rel = s ^ square[j];
			bad += cnt[rel];
			cout <<rel << ' ' << cnt[rel] << '\n';
		}
	}

	ll ans = 1ll * n * (n + 1) / 2 - bad;
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	for (int i = 0; i * i <= 4e5 + 1; ++i) {
		square[i] = i * i;
		num = i + 1;
	}
	cin >> t;
	while (t--) {
		solve();
	}
	
	return 0;
}
