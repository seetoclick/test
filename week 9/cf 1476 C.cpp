#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n, k;
const LL P = 1e9 + 7;
string s;

void solve() {
	cin >> n;
	vector<int> c(n + 1), a(n + 1), b(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> c[i];
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i)
		cin >> b[i];
	for (int i = 1; i <= n; ++i) {
		if (a[i] > b[i])
			swap(a[i], b[i]);
	}
	
	LL ans = 0, cnt = 0;	
	for (int i = 2; i <= n; ++i) {
		cnt = max(cnt, b[i] - a[i] + 1LL);
		ans = max(ans, cnt + c[i]);
		if (i < n && a[i + 1] != b[i + 1])
			cnt += a[i + 1] + c[i] - b[i + 1] + 1;
		else {
			//ans = max(ans, cnt + c[i]);
			cnt = 1;			
		}
		//cout << cnt << '\n';
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
