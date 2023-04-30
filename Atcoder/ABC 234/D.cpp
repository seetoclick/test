#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int t, n, k;
const int N = 2e5;


void solve() {
	cin >> n >> k;
	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 1; i < k; ++i) {
		int a;
		cin >> a;
		q.push(a);
	}
	
	for (int i = k; i <= n; ++i) {
		int a;
		cin >> a;
		q.push(a);
		if (q.size() > k) {
			q.pop();
		}
		cout << q.top() << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();		
	
	return 0;
}
