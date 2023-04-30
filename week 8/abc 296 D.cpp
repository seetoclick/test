#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const LL inf = 1e18;
LL n, m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	LL ans = inf;
	for (LL i = 1; i * i <= 2 * m; ++i) {
		LL a = i, b = (m - 1) / a + 1;
		if (a <= n && b <= n) {
			ans = min(ans, a * b);			
		}
	}
	
	if (ans == inf)
		cout << -1;
	else
		cout << ans;
	return 0;
}
