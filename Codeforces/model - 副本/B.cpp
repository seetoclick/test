#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, m, n;
const LL P = 1e9 + 7;
const int N = 5e4;

void solve() {
	cin >> m;
	vector<int> last(N + 1, 0);
	set<int> s;
	for (int i = 1; i <= m; ++i) {
		cin >> n;
		for (int j = 1, a; j <= n; ++j) {
			cin >> a;
			s.insert(a);
			last[a] = max(last[a], i);
		}
	}
	
//	for (int i = 1; i <= 4; ++i)
//		cout << last[i] << ' ';

	vector<pair<int, int>> b;
	vector<int> ans;
	for (auto id : s) {
		b.push_back({last[id], id});
	}
	sort(b.begin(), b.end());
//	for (auto x : b)
//		cout << x.first << ' ' << x.second<< '\n';
	int day = 1;
	for (auto p : b) {
		if (day > m)
			break;
		else if (p.first == day) {
			ans.push_back(p.second);
			day++;
		}
	}
	if (day < m) {
		cout << "-1\n";
		return;
	}
	
	for (auto p : ans)
		cout << p << ' ';
	cout << '\n';
	
//	if (day == 0) {
//		for (int i = ans.size() - 1; i >= 0; --i)
//			cout << ans[i] << ' ';
//		cout << "\n";
//	} else {
//		cout << "-1\n";
//	}
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
