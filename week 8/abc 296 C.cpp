#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int n, x;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> x;
	map<int, int> mp;
	vector<int> a(n + 1);
	
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		mp[a[i] - x] = 1;
	}
	for (int i = 1; i <= n; ++i) {
		if (mp[a[i]]) {
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No\n";
	return 0;
}
