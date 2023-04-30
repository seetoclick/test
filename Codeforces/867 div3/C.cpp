#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL q, t, n;
const LL P = 1e9 + 7;


void solve() {
	cin >> n >> t;
	vector<int> a(n + 1), b(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i)
		cin >> b[i];
	
	int ans = -1, index = -1;
	for (int i = 1; i <= n; ++i) {
		if (t >= a[i]) {
			if (ans < b[i]) {
				ans = b[i];
				index = i;
			}
			//ans = max(ans, b[i]);
		}
		t--;
		if (t == 0)
			break;
	}
	
	if (ans == -1)
		cout << "-1\n";
	else
		cout << index << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> q;
	while (q--) {
		solve();
	}
	
	return 0;
}
