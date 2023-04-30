#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int t;
LL v[2][100009], l[2][100009];
LL s[2][100009];

void solve() {
	LL n, n1, n2;
	cin >> n >> n1 >> n2;
	for (int i = 1; i <= n1; ++i) {
		cin >> v[0][i] >> l[0][i];
		s[0][i] = s[0][i - 1] + l[0][i];
	}
	for (int i = 1; i <= n2; ++i) {
		cin >> v[1][i] >> l[1][i];
		s[1][i] = s[1][i - 1] + l[1][i];				
	}
	
	LL cnt = 0, i = 1, j = 1, L = 1, R = 0;
	while (i <= n1 && j <= n2) {
		R = min(s[0][i], s[1][j]);
		//cout << L << ' ' << R << '\n';
		if (v[0][i] == v[1][j])
			cnt += (R - L + 1);
		if (s[0][i] < s[1][j]) {
			i++;
		} else if (s[0][i] > s[1][j]){
			j++;
		} else {
			i++, j++;
		}
		L = R + 1;
	}

	cout << cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}
