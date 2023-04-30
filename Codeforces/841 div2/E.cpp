#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t, n, m;

void solve() {
	cin >> n >> m;
	vector<ll> cnt(n + 1, 0); //cnt[i]: num of gcd = i
	for (int i = n; i >= 2; --i) {
		cnt[i] = n / i * (n / i - 1) / 2;
		//int sign = -1;
		for (int j = i + i; j <= n; j += i) {	
			cnt[i] -= cnt[j];
			//sign *= -1;
		}
	}
	
	ll cost = 0, edges = 0;
	for (int i = n; i >= 2; --i) {
		int num = i - 1; //num every time
		ll k = min(m - edges, cnt[i]) / num;	//choose k pairs
		cost += k * i;
		edges += k * num;
		//cout << "i = " << i << ' ' << edges << ' ' << cost << '\n';		
	}

	if (edges == m) 
		cout << cost << '\n';
	else
		cout << "-1\n";
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
