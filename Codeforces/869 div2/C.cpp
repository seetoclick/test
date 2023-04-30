#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n, q;
const LL P = 1e9 + 7;
int vis[200009];

void solve() {
	cin >> n >> q;
	vector<int> a(n + 1);
//	vector<int> vis;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		vis[i] = 0;
	}
	int cnt = 0;
	for (int i = 3; i <= n; ++i) {
		if (a[i - 2] >= a[i - 1] && a[i - 1] >= a[i]) {
			vis[++cnt] = i - 1;
		}
	}
	
	while (q--) {
		int l, r;
		cin >> l >> r;
		if (cnt == 0) {
			cout << r - l + 1 << '\n';
			continue;
		}
		int L = 1, R = cnt, index1, index2;
		if (vis[R] <= l || vis[L] >= r) {
			//cout << vis[L] << ' ' << vis[R] << ' ';
			cout << r - l + 1 << '\n';
		} else {
			int ans = r - l + 1;
			while (L < R) {
				int mid = (L + R) / 2;
				if (l > vis[mid]) {
					L = mid + 1;
				} else if (l < vis[mid]) {
					R = mid;
				} else {
					L = R = mid;
				}
			}
			index1 = L;
			L = 1, R = cnt;
			while (L < R) {
				int mid = (L + R) / 2;
				if (r > vis[mid]) {
					L = mid;
					if (R - L == 1) {
						if (r >= vis[mid + 1])
							L = R = mid + 1;
						else 
							L = R = mid;
					}
				} else if (r < vis[mid]) {
					R = mid - 1;
				} else {
					L = R = mid;
				}				
			}
			index2 = L;//cout << index1 << ' ' << index2 << '\n';
			if (vis[index1] >= r) {
				cout << ans << '\n';
			} else if (vis[index2] <= l) {
				cout << ans << '\n';
			} else if (vis[index2] > r) {
				if (vis[index1] == l)
					cout << ans - max(0, index2 - 1 - index1) << '\n';
				else
					cout << ans - (index2 - index1) << '\n';
			} else {
				ans -= (index2 - index1 + 1);
				if (vis[index1] == l)
					ans++;
				if (vis[index2] == r)
					ans++;
				cout << ans << '\n';
			}
//			cout << ans << '\n';
			//cout << l << ' '  << r << ' ' << index1 << ' ' << index2 << ' ';
		}
//		int ans = (r - l + 1);
//		if (index1 == l)
//			ans
		//cout << (r - l + 1) - (index2 - index1 + 1) << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}
