#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t, n;
const ll P = 1e9 + 7;
ll a[500];

void solve() {
	cin >> n;
	vector<int> odd, even;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] % 2 == 1) {
			odd.push_back(i);
		} else {
			even.push_back(i);
		}
	}
	
	if (odd.size() >= 3) {
		cout << "YES\n";
		cout << odd[0] << ' ' << odd[1] << ' ' << odd[2] << '\n';
	} else {
		if (odd.size() == 0)
			cout << "NO\n";
		else {
			if (even.size() < 2) {
				cout << "NO\n";
			} else {
				cout << "YES\n";
				cout << odd[0] << ' ' <<even[0] << ' ' << even[1] << '\n';
			}
		}
	}
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
