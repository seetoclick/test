#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n;
const LL P = 1e9 + 7;
const int N = 2e5;

void solve() {
	cin >> n;
	vector<LL> a(n + 1), b(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> a[i] >> b[i];		

	int cnt = 0;
	int up = -1, v = -1;	
	for (int i = 2; i <= n; ++i) {
		int d = __gcd(b[i - 1], b[i]);
		int g1 = b[i - 1] / d, g2 = b[i] / d;
		if (a[i] % g1 != 0 || a[i - 1] % g2 != 0) {
			cnt++;
			v = -1;
			up = -1;//cout << "x\n";
		} else {
			int tmpv = g1 * b[i], tmpup = __gcd(a[i] / g1, a[i - 1] / g2);
			if (up == -1) {
				up = tmpup;
				v = tmpv;
			} else {
				int d = __gcd(v, tmpv);
				int G1 = v / d, G2 = tmpv / d;
				if (up % G2 != 0 || tmpup % G1 != 0)  {
					cnt++;	
					v = -1;
					up = -1;//cout << "y\n";
				} else {
					up = tmpup;
					v = tmpv;					
				}
			}		
		}
		cout << up << ' ' << v << ' ' << cnt << '\n';
	}
	
	cout << cnt + 1 << '\n';
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
