#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n, k;
const LL P = 1e9 + 7;
string s;

void solve() {
	cin >> n >> s;
	
	int l = 0, r = 0;
	for (int i = 0; i <= n; ++i) {
		if (r <= i) {
			r = i + 1;
			if (i == n)
				r = n;
			while (r < n) {
				if (s[r - 1] == s[r])
					break;
				else
					r++;
			}
		}
		
		if (i >= 2) {
			if (i == 1)
				l = 0;
			else if (s[i - 1] == s[i - 2])
				l = i - 1;
		}
		
		int ans = 1;
		if (i > 0 && s[i - 1] == 'L')
			ans += i - l;
		if (i < n && s[i] == 'R')
			ans += r - i;
		cout << ans << ' ';		
	}
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
