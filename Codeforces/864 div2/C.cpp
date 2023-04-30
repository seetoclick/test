#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n, m, r[3];
const LL P = 1e9 + 7;


void solve() {
	cin >> n >> m;
	cout << "? 1 1" << endl;
	cout.flush();
	cin >> r[1];
	cout << "? " << n << ' ' << 1 << endl;
	cout.flush();
	cin >> r[2];
	
	if (1 + r[1] > n - r[2]) {
		if (r[1] < r[2])
			cout << '!' << n - r[2] << ' ' << 1 + r[1] << endl;
		else if (r[1] > r[2])
			cout << '!' << n - r[2] << ' ' << 1 + r[2] << endl;
		else {
			cout << "? " << 1 << ' ' << 1 + r[1] << endl;
			cout.flush();			
			cin >> r[3];
			cout << '!' << 1 + r[3] << ' ' << 1 + r[1] << endl;
		}
	} else if (1 + r[1] == n - r[2]) {
		cout << "? " << 1 + r[1] << ' ' << 1 << endl;
		cout.flush();			
		cin >> r[3];
		cout << '!' << 1 + r[1] << ' ' << 1 + r[3] << endl;		
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
