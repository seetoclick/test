#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int t, n;
LL F[50];

void solve() {
	int x, y;
	cin >> n >> x >> y;
	int ux = n, uy = n + 1;
	
	for (int i = 1; i <= n + 1; ++i) {
		if (y > F[ux]) {
			x = y, y = x - F[nx];			
			ux--, uy--;
		} else {
			
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	F[0] = F[1] = 1;
	for (int i = 2; i <= 45; ++i)
		F[i] = F[i - 1] + F[i - 2];	
	cin >> t;
	while (t--) {
		solve();
	}
	
	return 0;
}
