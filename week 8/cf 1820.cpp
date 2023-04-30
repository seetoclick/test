#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int t;

void solve() {
	string s;
	cin >> s;
	int n = s.size();
	if (n == 1) {
		if (s[0] == '1')
			cout << "1\n";
		else
			cout << "0\n";
		return;
	}
	
	LL L = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '1') {
			int j = i;
			while (s[j] == '1' && j < n)
				j++;
			if (j == n || s[j] != '1')
				j--;
			L = max(L, (LL)(j - i + 1));
			i = j;
		}
	}//cout << L << '\n';
	
	if (L == n) {
		cout << 1LL * n * n << '\n';
		return;
	}
	
	if (s[0] == '1' && s[n - 1] == '1') {
		int l = 0;
		while (s[l] == '1' && l < n)
			l++;
		if (l == n || s[l] != '1')
			l--;
		int r = n - 1;
		while (s[r] == '1' && r >= 0)
			r--;
		if (r == -1 || s[r] != '1')
			r++;		
		L = max(L, (LL)(l + 1 + n - r));
	}
	
	LL mid = (1 + L) / 2;
	cout << mid * (L + 1 - mid) << '\n';
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
