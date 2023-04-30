#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;

void solve() {
	string s;
	cin >> n >> s;
	
	for (int i = 1; i < n; ++i) {
		int l = 0;
		for (; l + i < (int)s.size(); ++l) {
			if (s[l + i] == s[l])
				break;
		}
		cout << l << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}
