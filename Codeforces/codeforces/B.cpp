#include<bits/stdc++.h>
using namespace std;

int  t, n;

void solve() {
	cin >> n;
	
	if (n & 1) {
		cout << n << ' ';
		int d = n / 2;
		for (int i = d; i >= 1; --i)
			cout << i << ' ' << i + d << ' ';
		cout << '\n';
	}
	else {
		int d = n / 2;
		for (int i = d; i >= 1; --i)
			cout << i << ' ' << i + d << ' ';
		cout << '\n';		
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