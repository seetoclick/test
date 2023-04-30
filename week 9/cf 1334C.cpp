#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n;
const LL P = 1e9 + 7;


void solve() {
	cin >> n;
	vector<LL> a(n + 1), b(n + 1);
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
	}
	
	LL s = a[0];
	for (int j = 1; j < n; ++j) {
		if (b[j - 1] < a[j]) {
			s += a[j] - b[j - 1];			
		}
	}//cout << s << '\n';
	
	LL ans = s;
	for (int i = 1; i < n; ++i) {
		s = a[i] + s;
		if (b[i - 1] >= a[i])
			s -= a[i - 1];
		else
			s -= a[i - 1] + a[i] - b[i - 1];
		
		if (b[(i - 2 + n) % n] < a[i - 1])
			s += (a[i - 1] - b[(i - 2 + n) % n]);
		ans = min(ans, s);//cout << s << '\n';
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
