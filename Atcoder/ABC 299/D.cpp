#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int t, n;

void solve() {
	cin >> n;
	int l = 1, r = n;
	char c;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		cout << "? " << mid << endl;
		cin >> c;
		if (c == '0') {
			l = mid;
		} else {
			r = mid;
		}
	}
	cout << "! " << l;
}

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	
	solve();
	
	return 0;
}
