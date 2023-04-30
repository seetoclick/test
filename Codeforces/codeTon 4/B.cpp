#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n;
const LL P = 1e9 + 7;

void solve() {
	cin >> n;
	if (n % 2 == 0) {
		cout << "-1\n";
		return;
	}
	
	vector<int> ans;
	int cnt = 0;
	while (n != 1) {
		cnt++;
		int r = n / 2;
		if (r % 2 == 1) {
			ans.push_back(2);
			n = r;
		} else {
			ans.push_back(1);
			n = r + 1;
		}
	}
	
	cout << cnt << '\n';
	for (int i = ans.size() - 1; i >= 0; --i)
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
