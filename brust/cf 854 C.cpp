#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int t;
string s;

void solve() {
	cin >> s;
	int n = s.size(), cnt[30] = {0};
	vector<char> ans(n);
	for (int i = 0; i < n; ++i) {
		cnt[s[i] - 'a']++;	
	}	

	int L = 0, R = n - 1, x = -1, y = -1;
	for (int i = 0; i <= 25; ++i) {
		if (cnt[i] % 2 == 1) {
			if (x == -1)
				x = i;
			else if (x != -1 && y == -1)
				y = i;
		}
	}
	if (x == -1 && y == -1) {
		for (int i = 0; i <= 25; ++i) {
			while (cnt[i]) {
				ans[L] = ans[R] = char('a' + i);
				L++, R--;
				cnt[i] -= 2;
			}
		}
	}
	else if (y == -1) {
		for (int i = 0; i <= 25; ++i) {
			while (cnt[i] > 1) {
				ans[L] = ans[R] = char('a' + i);
				L++, R--;
				cnt[i] -= 2;
			}
		}		
		ans[L] = char('a' + x);
	}
	else {
		int i = 0;
		for (; i <= y; ++i) {
			while (cnt[i] > 1) {
				ans[L] = ans[R] = char('a' + i);
				L++, R--;
				cnt[i] -= 2;
			}
		}	
		ans[L] = char('a' + y), ans[R] = char('a' + x);
		for (; i <= 25; ++i) {
			while (cnt[i]) {
				ans[++L] = char('a' + i);
				cnt[i]--;
			}
		}
	}
	
	for (int i = 0; i < n; ++i)
		cout << ans[i];
	cout << '\n';
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

