#include <bits/stdc++.h>
using namespace std;

int t, n, k;

void solve() {
	string s1, s2;
	cin >> n >> k >> s1 >> s2;
	int cnt_s1[30] = {0}, cnt_s2[30] = {0};
	for (int i = 0; i < n; ++i) {
		cnt_s1[s1[i] - 'a']++;
		cnt_s2[s2[i] - 'a']++;
	}
	for (int i = 0; i <= 25; ++i) {
		if (cnt_s1[i] != cnt_s2[i]) {
			cout << "NO\n";
			return;
		}
	}
	
	if (n - k <= k - 1) {
		for (int i = max(n - k, 0); i <= min(k - 1, n - 1); ++i) {
			if (s1[i] != s2[i]) {
				cout << "NO\n";
				return;
			}
		}
	}
	for (int i = 0; i <= 25; ++i) {
		if (cnt_s1[i] != cnt_s2[i]) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
	return;
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
