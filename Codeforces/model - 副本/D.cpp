#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n;
const LL P = 1e9 + 7;


void solve() {
	cin >> n;
	vector<LL> a(n);
	LL Ma = -2 * P, Mi = 2 * P;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		Ma = max(Ma, a[i]);
		Mi = min(Mi, a[i]);
	}
	sort(a.begin(), a.end());
	
	vector<int> ans;
	int l = 1, r = n - 1;
	LL s = a[0];
	ans.push_back(a[0]);
	for (int i = 1; i < n; ++i) {
		if (abs(s + a[l]) < Ma - Mi) {
			s += a[l];
			ans.push_back(a[l]);
			l++;
		} else if (abs(s + a[r]) < Ma - Mi){
			s += a[r];
			ans.push_back(a[r]);
			r--;
		}
	}
	
	if (n == 1 || ans.size() != n) {
		cout << "No\n";
	} else {
		cout << "Yes\n";
		for (auto p : ans)
			cout << p << ' ';
		cout << '\n';
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
