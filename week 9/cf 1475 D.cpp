#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n, m, k;
const LL P = 1e9 + 7;
string s;

void solve() {
	cin >> n >> m;
	vector<int> a(n + 1), a1, a2;
	LL s = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		s += a[i];
	}
	for (int i = 1, b; i <= n; ++i) {
		cin >> b;
		if (b == 1) {
			a1.push_back(a[i]);
		} else {
			a2.push_back(a[i]);
		}
	}
	
	if (s < m) {
		cout << "-1\n";
		return;
	}
	
	sort(a1.begin(), a1.end());
	sort(a2.begin(), a2.end());
	int n1 = a1.size(), n2 = a2.size();
	n1--, n2--;
	s = 0;
	int ans = 0;
	while (m > 0) {
		if (n1 < 0) {
			ans += 2;
			m -= a2[n2];
			n2--;
		} else if (n2 < 0) {
			ans++;
			m -= a1[n1];
			n1--;
		} else if (a1[n1] >= m) {
			ans++;
			break;
		} else if (a1[n1] >= a2[n2]) {
			ans++;
			m -= a1[n1];
			n1--;
		} else if (n1 >= 1 && a1[n1] + a1[n1 - 1] >= a2[n2]) {
			ans += 1;
			m -= a1[n1];
			n1--;
		} else {
			ans += 2;
			m -= a2[n2];
			n2--;
		}//cout << n1 << ' ' << n2 << ' ' << ans <<  '\n';
	}	
	cout << ans << '\n';	
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
