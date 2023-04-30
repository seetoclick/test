#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int t, n;
int a[1009];
void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	string s;
	cin >> s;
	int cnt = 0;
	
	for (int i = 0; s[i + 3] != '#'; ++i) {
		if (s[i] == 'd' && s[i + 1] == 'a' && s[i + 2] == 'n' && s[i + 3] == 'g')
			cnt++;
	}
	int v = 1000;
	for (int i = 1; i <= n; ++i) {
		a[i] = abs(a[i] - cnt);
		v = min(v, a[i]);
	}	
	
	int cntt = 0, ans[1001];
	for (int i = 1; i <= n; ++i) {
		if (a[i] == v)
			ans[++cntt] = i;
	}
	for (int i = 1; i < cntt; ++i)
		cout << ans[i] << ' ';
	cout << ans[cntt];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	
	return 0;
}
