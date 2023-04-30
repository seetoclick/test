#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n;
const LL P = 1e9 + 7;

char s[10];
void solve() {
	cin >> s;
	int n = strlen(s);
	int ans = 1, cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '?') {
			cnt++;
			if (i == 0)
				ans *= 9;
			else
				ans *= 10;
		}
	}
	if (s[0] == '0') 
		cout << "0\n";
	else if(cnt == 0 && s[0] != '0')
		cout << "1\n";
	else
		cout << ans << '\n';
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
