#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int t, n, q;
bool vis[500009];

void solve() {
	cin >> n >> q;
	priority_queue<int, vector<int>, greater<int> > q;
	for (int i = 1; i <= n; ++i)
		q.push(i);
	
	while (q--) {
		int op; 
		cin >> op;
		if (op == 1) {
			int p = q.top();
			q.pop();
			q2.push(p);
			//cout << p << '\n';
		} else if (op == 2) {
			int x;
			cin >> x;
			//q2.push(x);
		} else {
			int p = q2.top();
			q2.pop();
			cout << p << '\n';
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}
