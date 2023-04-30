#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n;
const LL P = 1e9 + 7;
LL p[200009];

void solve() {
	cin >> n;
	for (int i = 1; i <= 2 * n; ++i) {
		cin >> p[i];
	}

	if (n == 1) {
		cout << abs(p[1] - p[2]) << '\n';
	} else {
		LL s = 0;
		for (int i = 1; i <= 2 * n; ++i)
			s += abs(p[i]);
		if (n % 2 == 1)
			cout << s << '\n';
		
		LL s1 = 0;
		for (int i = 1; i <= 2 * n; ++i) {
			s1 += abs(p[i] + 1);
		}
		LL s2 = s1 - abs(p[1] + 1) + abs(p[1] - n);
		for (int i = 2; i <= 2 * n; ++i) {
			s2 = min(s2, s1 - abs(p[i] + 1) + abs(p[i] - n));
			//cout << i << ' '<< s1 << '\n';
		}

		if (n == 2) {
			s2 = min(s2, abs(p[1] - 2) + abs(p[2] - 2) + abs(p[3] - 2) + abs(p[4] - 2));
		}
		cout << min(s, s2) << '\n';
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
