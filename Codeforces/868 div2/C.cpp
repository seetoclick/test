#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n;
const LL P = 1e9 + 7;
//int cnt[10000009];

void solve() {
	cin >> n;
	vector<int> a(n + 1);
	vector<int> pr;
	map<int, int> cnt;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		for (int j = 2; j * j <= a[i]; ++j) {
			if (a[i] % j == 0) {
				if (!cnt[j])
					pr.push_back(j);
				int num = 0;
				while (a[i] % j == 0) {
					a[i] /= j;
					num++;
				}
				cnt[j] += num;
			}
		}
		if (a[i] != 1) {
			if (!cnt[a[i]])
				pr.push_back(a[i]);
			cnt[a[i]]++;
		}		
	}

	LL ans = 0, num = 0;
	for (auto p : pr) {
		//cout << p << ' ' << cnt[p] << '\n';
		int x = cnt[p];
		ans += x / 2;
		num += x % 2;
	}
	ans += num / 3;
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
