#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int t, n;
LL S[200009];

void solve() {
	cin >> n;
	for (int i = 1; i <= n + 5; ++i)
		S[i] = 0;
	vector<LL> a(n + 1), b(n + 1), delta(n + 1, 0), ans(n + 6, 0);
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
		S[i] = S[i - 1] + b[i];
	}

	for (int i = 1; i <= n; ++i) {
		int R = upper_bound(S + 1, S + n + 1, a[i] + S[i - 1]) - S;
		ans[R] += a[i] - (S[R - 1] - S[i - 1]);
		delta[i] += 1;
		delta[R] -= 1;//cout << i << ' ' << R << ' ' << ans[R] << '\n';
	}
	LL s = 0;
	for (int i = 1; i <= n; ++i) {
		s += delta[i];
		ans[i] += b[i] * s;
		cout << ans[i] << ' ';
	}
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
