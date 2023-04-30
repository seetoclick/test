#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n, k;
const LL P = 1e9 + 7;


void solve() {
	int a[50] = {0}, S[50] = {0};
	cin >> n >> k;
	k = n * (n + 1) / 2 - k;
	int s = 0;
	a[1] = 1;
	for (int i = 1; i <= n; ++i) {
		a[i] = 2 * i - 1;	
		S[i] = i * i;
	}

	for (int i = 1; i <= n; ++i) {
		if (k == s)
			break;
		else if (k - s >= n - i + 1) {
			a[i] = -1000;
			s += n - i + 1;
		} else {
			a[i] = -S[i + k - s - 1] + S[i] - 1;
			break;
		}

	}
	
	for (int i = 1; i <= n; ++i)
		cout << a[i] << ' ';
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
