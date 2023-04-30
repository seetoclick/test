#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 3e5;
int n, a[N + 5];
LL ans[N + 5];
vector<int> child[N + 5];

vector<int> mergr(vector<int>& s, vector<int>& t) {
	vector<int> r;
	while (!s.empty() || !t.empty()) {
		
	} 
}

vector<int> calc(int i) {
	if (child[i].size() == 0) {
		ans[i] = 0;
		vector<int> t;
		t.push_back(i);
		return t;
	}
	
	LL rel = 0;
	vector<int> t;
	for (auto e : child[i]) {
		vector<int> s = calc(e);
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		s = merge(s, t);
	}
	for (auto x : t)
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int p;
		child[p].push_back(i);
	}
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	calc(1);
	
	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}
