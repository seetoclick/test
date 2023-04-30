#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n;
const LL P = 1e9 + 7;


void solve() {
	cin >> n;
	vector<int> a(n + 1);
	int cnt = 0;
	bool check = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		cnt++;
		if (a[i] <= cnt) {
			check = 1;
		}
	}
	if (check)
		cout << "YES\n";
	else
		cout << "NO\n";
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
