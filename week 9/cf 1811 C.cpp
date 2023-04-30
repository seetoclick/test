#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n;
const LL P = 1e9 + 7;


void solve() {
	cin >> n;
	vector<int> a(n + 1, -1), b(n + 1);
	for (int i = 1; i <= n - 1; ++i) {
		cin >> b[i]; //b[i] = max(a[i], a[i + 1]);
	}
	for (int i = 1; i <= n - 2; ++i) {
		//a[i] = b[i];
		if (b[i] < b[i + 1]) {
			a[i + 2] = b[i + 1]; 
			
		} else if (b[i] > b[i + 1]) {
			a[i] = b[i];
			
		}
	}
	for (int i = 1; i <= n - 1; ++i) {
		if (a[i] == -1)
			a[i] = b[i];
		if (a[i + 1] == -1)
			a[i + 1] = b[i];
		if (a[i] > b[i])
			a[i] = b[i];
		if (a[i + 1] > b[i])
			a[i + 1] = b[i];
	}
	
	for (int i = 1; i <= n; ++i)
		cout << a[i] << ' ';
	cout << '\n';
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
