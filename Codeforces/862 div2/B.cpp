#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n;
const LL P = 1e9 + 7;

void solve() {
	cin >> n;
	vector<char> s(n, 0);
	char minc = 'z';
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
		minc = min(minc, s[i]);
	}
	
	int j = n - 1;
	for (; j >= 0; --j) {
		if (s[j] == minc)
			break;
	}
	cout << minc;
	for (int i = 0; i < j; ++i)
		cout << s[i];
	for (int i = j + 1; i < n; ++i)
		cout << s[i];
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
