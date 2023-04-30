#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n;
const LL P = 1e9 + 7;
int a[200009];
string s;

void solve() {
	cin >> n;
	vector<int> mp(1e6 + 1, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		mp[a[i]]++;
	}
	sort(a + 1, a + n + 1);
	
	LL ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] == a[i - 1])
			continue;
		for (int j = 1; j * j <= a[i]; ++j) {
			if (a[i] % (j * j) == 0) {
				int x = a[i] / j;
				int y = x / j;
				if (j == 1) {
					if (mp[x] >= 3)
						ans += mp[x] * (mp[x] - 1) * (mp[x] - 2);
				} else {
					ans += mp[a[i]] * mp[x] * mp[y];
				}//cout << i << ' ' << j << ' ' << ans << '\n';
			}
		}
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
