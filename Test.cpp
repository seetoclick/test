#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int t, n, k;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> t;
	while (t--) {
		cin >> k >> n;
		int s;
		for (int i = k; i >= 1; --i) {
			if (i * i - 3 * i <= 2 * n + 2 * k - 2) {
				s = i;
				break;
			}
		}
		
		for (int i = 1; i <= s; ++i)
			cout << 1 + i * (i - 1) / 2 << ' ';
		for (int i = s + 1; i <= k; ++i)
			cout << 1 + s * (s - 1) / 2 + i - s << ' ';
		cout << '\n';
	}
	
	return 0;
}
