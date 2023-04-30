#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int t, n;

void solve() {
	cin >> n;
	vector<int> a(n + 1);
	map<int, int> cnt1, cnt2;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		cnt1[a[i]] = 1;
	}
	int mex = n;
	int l = 0, r = 0;
	for (int i = 0; i <= n; ++i) {
		if (cnt1[i] == 0) {
			mex = i;
			break;
		}
	} //cout << mex << ' ';
	if (mex == n) {
		cout << "No\n";
		return;
	}
	for (int i = 1; i <= n; ++i) {
		if (a[i] == mex + 1 && l == 0)
			l = r = i;
		if (a[i] == mex + 1 && l != 0)
			r = i;
	} //cout << l << ' '<< r << ' ';
	if (l) {
		for (int i = l; i <= r; ++i)
			a[i] = mex;
		for (int i = 1; i <= n; ++i) {
			cnt2[a[i]] = 1;
		}
		int mex2 = n;
		for (int i = 0; i <= n; ++i) {
			if (cnt2[i] == 0) {
				mex2 = i;
				break;
			}
		} //cout << mex2 << '\n';
		if (mex2 == mex + 1) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}		
	} else {
		cout << "Yes\n";
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
