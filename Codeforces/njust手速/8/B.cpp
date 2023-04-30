#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t = 1, n;
int s[1045][1045] = {0};
int d(int x) {
	int cnt = 0;
	while (x) {
		cnt++;
		x /= 10;
	}
	return cnt;
}

void solve() {
	cin >> n;
	
	for (int i = 2; i <= n + 1; i += 2) {
		for (int j = 1; j < i; ++j) {
			s[j][i - j] = i;
		}
	}
	for (int i = n + 2; i <= 2 * n; i += 2) {
		for (int j = n; i - j <= n; --j) {
			s[i - j][j] = i;
		}
	}
	
	s[1][2] = 1;
	for (int i = 3; i <= n + 1; i += 2) {
		for (int j = 1; j < i; ++j) {
			s[j][i - j] =  i - 2;
		}
	}	
	for (int i = n + 3; i <= 2 * n; i += 2) {
		for (int j = n; i - j <= n; --j) {
			s[i - j][j] = i - 2;
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (d(s[i][j]) == 1) {
				cout << "   " << s[i][j];
			} else if (d(s[i][j]) == 2) {
				cout << "  " << s[i][j];
			} else if (d(s[i][j]) == 3) {
				cout << " " << s[i][j];  
			} else 
				cout << s[i][j];
		}
		cout << '\n';
	}	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	//cin >> t;
	while (t--) {
		solve();
	}
	
	return 0;
}
