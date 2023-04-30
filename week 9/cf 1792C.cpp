#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int t, n;

void solve() {
	cin >> n;
	vector<int> p(n + 1), pos(n + 2);
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
		pos[p[i]] = i;
	}
	pos[0] = n + 1, pos[n + 1] = 0;
	
	if (n == 1) {
		cout << "0\n";
		return;
	}
	
	int l = n / 2, r = n + 1 - l;//cout << l << ' ' << r << '\n';
	while (l >= 1) {
		if (r - l == 1 && pos[l] < pos[r])
			l--, r++;
		else if (pos[l] < pos[l + 1] && pos[r - 1] < pos[r])
			l--, r++;
		else
			break;
	}
	
	cout << l  << '\n';
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
