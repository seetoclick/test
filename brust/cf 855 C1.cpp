#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int t, n;

void solve() {
	cin >> n;
	LL ans = 0;
	priority_queue<int, vector<int>, less<int> > q;
	for (int i = 1; i <= n; ++i) {
		int a;
		cin >> a;
		if (a) 
			q.push(a);
		else if (!q.empty()){
			int p = q.top();
			ans += p;
			q.pop();
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
