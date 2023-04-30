#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t = 1, n;
string s;


void solve() {
	cin >> n >> s;
	n %= 26;
	for (int i = 0; i < s.size(); ++i) {
		if (char(s[i] + n) > 'Z')
			cout << char(s[i] + n - 26);
		else
			cout << char(s[i] + n);
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	//cin >> t;
	while (t--) {
		solve();
	}
	
	return 0;
}
