#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int t, n;

void solve() {
	cin >> n;
	vector<int> a(n + 1, 0), s(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	
	int l = 1, r = n;
	while (l < r) {
		int mid = (l + r) / 2, mass;
		cout << "? " << mid - l + 1 << endl;
		for (int i = l; i <= mid; ++i)
			cout << i << ' ';
		cout << endl;
		cin >> mass;
		
		if (s[mid] - s[l - 1] == mass) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	cout << "! " << l << endl;
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
