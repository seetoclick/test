#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n;
const LL P = 1e9 + 7;
int a[200], b[200];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int j = 1; j <= n; ++j)
		cin >> b[j];
	
	bool oka = 1, okb = 1;
	for (int i = 1; i <= n - 1; ++i) {
		if (a[n] < min(a[i], b[i]) || b[n] < min(a[i], b[i])) {
			cout << "No\n";
			return;
		}
		if (a[n] < max(a[i], b[i]))
			oka = 0;
		if (b[n] < max(a[i], b[i]))
			okb = 0;
	}
	
	if (oka || okb)
		cout << "Yes\n";
	else
		cout << "No\n";
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
