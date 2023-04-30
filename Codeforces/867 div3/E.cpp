#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n;
const LL P = 1e9 + 7;
string s;

void solve() {
	cin >> n >> s;
	if (n % 2 == 1) {
		cout << "-1\n";
		return;
	}
	int cnt[30] = {0};
	for (int i = 0; i < n; ++i) {
		cnt[s[i] - 'a']++;
	}
	for (int i = 0; i < 26; ++i) {
		if (cnt[i] > n / 2) {
			cout << "-1\n";
			return;
		}
	}
	int c[30] = {0};
	int l = 0, r = n - 1, ans = 0;
	while (l < r) {
		if (s[l] == s[r]) {
			c[s[l] - 'a']++;
		
		}
		l++, r--;
	}
	for (int i = 0; i < 26; ++i)
		ans += c[i];
	cout << (ans + 1) / 2 << '\n';
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
