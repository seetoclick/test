# include <bits/stdc++.h>
using namespace std;

int n;

int C(int n) {
	return n * (n - 1) / 2;
}

void solve() {
	cin >> n;
	vector<int> cnt(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		int a;
		cin >> a;
		cnt[a]++;
	}
	
	int ans = C(n);
	for (int i = 1; i <= n; ++i) {
		ans -= C(cnt[i]);
	}
	
	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}
