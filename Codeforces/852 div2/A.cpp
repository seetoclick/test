#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t, n, m;

void solve() {
	ll a, b;
	cin >> a >> b >> n >> m;
	
	ll cost = 0;
	if (a <= b) {
		if (n <= m) {
			cost = n * a;
		} else {
			ll num = n / (m + 1);
			cost = num * m * a + a * (n % (m + 1)); 
		}
	} else {
		if (n <= m) {
			cost = n * b;
		} else {
			if ((m * a <= (m + 1) * b)) {
				ll num = n / (m + 1);
				cost = num * m * a + b * (n % (m + 1));				
			} else {
				cost = n * b;	
			}
		}
			
	}
	
	cout << cost << '\n';
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
