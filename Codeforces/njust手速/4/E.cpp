#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t = 1, n, k;
ll tong[200009] = {0};

void solve() {
	cin >> n >> k;
	vector<ll> s(n + 1);
	map<ll, int> mp;
	mp[0] = 1, s[0] = 0;
 	for (int i = 1; i <= n; ++i) {
		ll tmp;
		cin >> tmp;
		s[i] = (s[i - 1] + tmp) % k;
		ll num = (s[i] - i + k * 200000) % k;
		mp[num]++;
//		if (num == -1)
//			cout << i << "  here  " << '\n';
	}
	
	ll ans = 0;
	for (auto i : mp) {
		ll num = i.second;
		if (num >= 2) {
//			cout << i.first << ' ' << num << ' ';
			ans = (ans + num * (num - 1) / 2);	
//			cout << ans << '\n';
		}
	}
	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	//cin >> t;
	while (t--) {
		solve();
	}
	
	return 0;
}
