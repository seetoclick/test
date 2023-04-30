#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int K = (1 << 26) - 1;
LL t, n;
string s;

void solve() {
	cin >> n;
	vector<int> cnt(n + 1, 0), pos[30];
	for (int i = 1; i <= n; ++i) {
		cin >> s;
		int word[30] = {0}, vis[30] = {0};
		for (auto &c : s) {
			word[c - 'a']  ^= 1;
			vis[c - 'a'] = 1;
		}
		for (int j = 0; j < 26; ++j) {
			if (vis[j] && word[j])
				cnt[i] += (1 << j);
			else if (!vis[j])
				pos[j].push_back(i);
		}
	}
	
	LL ans = 0;
	for (int i = 0; i < 26; ++i) {
		int k = K ^ (1 << i);
		map<int, int> f;
		for (auto &x : pos[i]) {
			f[cnt[x] ^ k]++;
		}
		for (auto &x : pos[i]) {
			ans += f[cnt[x]];
		}
	}
	
	cout << ans / 2 << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}
