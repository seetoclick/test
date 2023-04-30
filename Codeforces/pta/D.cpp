#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int t, n;

void solve() {
	int n, m;
	bool ok[1050] = {0};
	cin >> n >> m;
	int t[1050], a[1050];
	double b[1050];	
		
	for (int i = 1; i <= m; ++i) {
		cin >> t[i] >> a[i] >> b[i];
	}
	int out = n;
	for (int i = 1; i <= m; ++i) {
		if (t[i] == 1) {
			if ((b[i] < 37.5 || t[i] != T))
				ok[a[i]] = true;
			else 
				out--;
		}
		else if (ok[i] && (b[i] < 37.5 || t[i] != T))
			ok[a[i]] = true;
		else {
			out--;
			ok[a[i]] = false;			
		}

	}
	
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (ok[i] == true) {
			cnt++;
		}
	}
	cout << cnt << '\n';
	for (int i = 1; i <= n; ++i) {
		if (ok[i] == true) {
			cout << i << ' ';
		}
	}	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	
	return 0;
}
