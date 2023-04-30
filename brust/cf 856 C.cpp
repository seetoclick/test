#include <bits/stdc++.h>
using namespace std;

int t;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1), ans(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	
	ans[1] = 1;
	for (int i = 2; i <= n; ++i) {
		ans[i] = ans[i - 1];
		if (a[i - ans[i - 1]] >= ans[i - 1] + 1)
			ans[i]++;
	}
	
	for (int i = 1; i <= n; ++i)
		cout << ans[i] << ' ';
	cout << '\n';
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
