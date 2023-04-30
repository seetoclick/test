#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n, m, k;
const LL P = 1e9 + 7;
string s;

void solve() {
	cin >> n >> m >> k;
	vector<int> a(k + 1), b(k + 1), numa(n + 1, 0), numb(m + 1, 0);
	for (int i = 1; i <= k; ++i) {
		cin >> a[i];
		numa[a[i]]++;
	}
	for (int i = 1; i <= k; ++i) {
		cin >> b[i];
		numb[b[i]]++;
	}
	
	LL ans = 0;
	for (int i = 1; i <= k; ++i) {
		ans += (k - i + 1) - (numa[a[i]] + numb[b[i]] - 1);
		numa[a[i]]--;
		numb[b[i]]--;
		//cout << ans << ' ';
	}
	cout << ans << '\n';
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
