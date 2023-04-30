#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int t, n;

void solve() {
	cin >> n;
	vector<int> a(n + 1);	
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	int cnt = 0, i = 1;
	LL S = 0;
	while (i <= n) {
		if (i == n && S + a[n] == 0) {
			cnt++;
			break;
		}
		while (a[i] != 0 && i <= n) {
			S += a[i];
			if (S == 0)
				cnt++;
			i++;
		}
		
		i++;
		if (i > n)
			break;
		map<LL, int> mp;
		LL preS = S;
		while (a[i] != 0 && i <= n) {
			S += a[i];
			mp[S]++;
			i++;
		}
		int v = 0, num = 0;
		for (auto &x : mp) {
			if (num < x.second) {
				num = x.second;
				v = x.first;
			}
		}
		S -= v;
		cnt += num;
		if (preS - v == 0)
			cnt++;
	}

	cout << cnt << '\n';
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
