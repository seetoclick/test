#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int t, n;
string s,ans[100009];
	
void solve() {


	int cnt = 0, num = 0;
	while (cin >> s) {
		++num;
		for (int i = 0; s[i + 3]; ++i) {
			if (s[i] == 'W' && s[i + 1] == 'o' && s[i + 2] == 'W') {
				ans[num] += "World of Warcraft";
				i = i + 2;
				continue;
			}
			else {
				if (s[i] == 'w' && s[i + 1] == 'o' && s[i + 2] == 'w')
					cnt++;
			}
			ans[num] += s[i];
		}		
	}

	cout << cnt << '\n';
	for (int i = 1; i <= num; ++i)
		cout << ans[i] << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	
	return 0;
}
