#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t, n;

void solve() {
	cin >> n;
	vector<int> cnt2(n + 1, 0);

	for (int i = 1; i <= n; ++i) {
		int tmp;
		cin >> tmp;
		cnt2[i] = cnt2[i - 1];
		if (tmp == 2)
			cnt2[i]++;
	} 
	
	for (int i = 1; i < n; ++i) {
		if (cnt2[i] == (cnt2[n] - cnt2[i])) {
			cout << i << '\n';
			return;
		}
	}
	cout << "-1\n";
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
