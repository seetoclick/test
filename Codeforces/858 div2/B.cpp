#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n;
const LL P = 1e9 + 7;


void solve() {
	cin >> n;
	vector<int> a(n + 1);
	int cnt = 0, cnt1 = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] == 0)
			cnt++;
		if (a[i] == 1)
			cnt1++;
	}
	//cout << cnt << '\n';
	if (cnt <= n - cnt + 1)
		cout << "0\n";
	else {
		if (cnt1 && cnt + cnt1 == n) {
			cout << "2\n";
		} else {
			cout << "1\n";
		}
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
