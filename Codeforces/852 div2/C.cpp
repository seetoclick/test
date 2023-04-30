#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t, n;

void solve() {
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	if (n == 1) {
		cout << "-1\n";	
		return;
	}

	
	int l = 1, r = n, L = 1, R = n;
	while (l <= r) {
		int ok = 2;
		
		if (a[l] == L) {
			l++;
			L++;
			ok--;
		} else if (a[l] == R) {
			l++;
			R--;
			ok--;
		}
		
		if (a[r] == L) {
			r--;
			L++;
			ok--;
		} else if (a[r] == R) {
			r--;
			R--;
			ok--;
		}		
		
		if (ok == 2) {
			cout << l << ' ' << r << '\n';
			return;
		}
	}
	
	cout << "-1\n";
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
