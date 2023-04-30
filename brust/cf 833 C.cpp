#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n, s;

void solve() {
	cin >> n;
	vector<LL> a(n + 1);
	
	int cnt = 0;
	LL s = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	a[0] = -1;
	
	for (int i = 1; i <= n; ++i) {
		if (a[i - 1] == 0 && a[i] != 0) {
			map<LL, int> mp;
			s = 0;
			while (a[i] != 0 && i <= n) {
				s += a[i];
				mp[s]++;				
				i++;				
			}
			int x = 0;
			for (auto u : mp)
				x = max(x, u.second);
			cnt += x;
			
			if (i > n)
				break;
			else
				i--;
		} else if (a[i - 1] != 0 && a[i] != 0) {
			s += a[i];
			if (s == 0)
				cnt++;
		}
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
