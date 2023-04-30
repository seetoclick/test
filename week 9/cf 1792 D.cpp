#include <bits/stdc++.h>
using namespace std;

int t, n, m;

void solve() {
	cin >> n >> m;
	vector<vector<int>> p(n, vector<int>(m));
	vector<vector<int>> tri(n * m, vector<int>(m, -1));
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		vector<int> pos(n);
		for (int j = 0; j < m; ++j) {
			cin >> p[i][j];
			p[i][j]--;
			pos[p[i][j]] = j;
		}
		
		int cur = 0;		
		for (int j = 0; j < m; ++j) {
			if (tri[cur][pos[j]] == -1) {
				tri[cur][pos[j]] = ++cnt;
			}			
			cur = tri[cur][pos[j]];
		}
	}

//cout << tri[0][2] << ' ' << tri[1][0]<<' ' << tri[2][2] <<  '\n';
	for (int i = 0; i < n; ++i) {
		int cur = 0, h = 0;
		for (int j = 0; j < m; ++j) {
			//cout << i << ' ' << p[i][j] << ' ' << tri[cur][p[i][j]] << '\n';
			if (tri[cur][p[i][j]] == -1)
				break;
			else {
				cur = tri[cur][p[i][j]];
				h++;
			}
		}
		cout << h << '\n';
	}
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
