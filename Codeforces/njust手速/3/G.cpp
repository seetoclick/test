#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t = 1, n;

void solve() {
	char a, b, c;
	cin >> a >> b >> c;
	int cnt = 0;	
	cnt += (a == 'A');
	cnt += (b == 'A');
	cnt += (c == 'A');
	
	if (cnt == 0 || cnt == 3) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
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
