#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int t, n, s1, s2;
pair<int, int> a[200009];
int ans1[200009], ans2[200009];

void solve() {
	cin >> n >> s1 >> s2;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a + 1, a + n + 1);
	
	int cnt1 = 0, cnt2 = 0, t1 = 0, t2 = 0;
	for (int i = n; i >= 1; --i) {
		int id = a[i].second;
		if (t1 + s1 <= t2 + s2) {
			ans1[++cnt1] = id;
			t1 = t1 + s1;
		} else {
			ans2[++cnt2] = id;
			t2 = t2 + s2;			
		}
	}
	
	cout << cnt1 << ' ';
	for (int i = 1; i <= cnt1; ++i)
		cout << ans1[i] << ' ';
	cout << '\n';
	cout << cnt2 << ' ';
	for (int i = 1; i <= cnt2; ++i)
		cout << ans2[i] << ' ';
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
