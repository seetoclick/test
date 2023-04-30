#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t, n;

void solve() {
	cin >> n;
	vector<int> p(n + 1), q(n + 1), mexp(n + 1), mexq(n + 1);
	set<int> sp, sq;
	for (int i = 1; i <= n + 1; ++i) {
		sp.insert(i);
		sq.insert(i);
	}
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
		sp.erase(p[i]);
		mexp[i] = *sp.begin();
	}
	for (int i = 1; i <= n; ++i) {
		cin >> q[i];
		sp.erase(q[i]);
		mexp[i] = *sq.begin();		
	}
	
	
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
