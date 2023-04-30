#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 1e5;
int n, a[N + 5], dp[N + 5];
vector<int> G[N + 5];

void dfs(int i) {
	if (dp[i] != -1)
		return;
	int state = 0;
	for (auto p : G[i]) {
		dfs(p);
		if (dp[p] == 0)
			state = 1;
	}
	dp[i] = state;
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		dp[i] = -1;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i - a[i]; j >= 1; j -= a[i])
			if (a[j] > a[i])
				G[i].push_back(j);
		for (int j = i + a[i]; j <= n; j += a[i])
			if (a[j] > a[i])
				G[i].push_back(j);		
	}
	for (int i = 1; i <= n; ++i) {
		dfs(i);
	}
	for (int i = 1; i <= n; ++i) {
		if (dp[i] == 1)
			cout << "A";
		else if (dp[i] == 0)
			cout << "B";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}
