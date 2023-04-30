#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n, m, k;
const LL P = 1e9 + 7;
const int inf = 0x3f3f3f3f;
char s[1024][1024];

void solve() {
	cin >> n >> m;
	int row = -1, col = -1;
	bool okr = 0, okc = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			cin >> s[i][j];
	}
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			if (s[i][j] == '*') {
				int cntr = 0, cntc = 0;
				if (!okr) {
					for (int k = 1; k <= m; ++k)
						if (s[i][k] == '*' && k != j) {
							row = i;
							okr = 1;
							cntr++;
						s[i][k] = '.';							
					}
				} else if (!okc) {
					for (int k = 1; k <= n; ++k)
						if (s[k][j] == '*' && k != i) {
							col = j;
							okr = 1;
							cntc++;
						s[k][j] = '.';							
					}					
				} else if (!cntr && !cntc && !okr && !okc) {
					okr = okc = 1;
					row = i, col = j;
				} else {
					cout << "NO";
					return;
				}
			}
	}
	
	cout << "YES\n";
	cout << row << ' ' << col;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	//	cin >> t;
	//	while (t--) {
	solve();
	//	}
	
	return 0;
}
