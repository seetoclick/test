#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int t, n, T;

void solve() {
	cin >> n >> T;
	vector<int> c(n + 1), r(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> c[i];
	for (int i = 1; i <= n; ++i)
		cin >> r[i];
	
	int Trank = -1, Tpos, Frank = -1, Fpos;
	for (int i = 1; i <= n; ++i) {
		if (c[i] == c[1]) {
			//Frank = max(Frank, r[i]);
			if (Frank < r[i]) {
				Frank = r[i];
				Fpos = i;
			}
		}
		if (c[i] == T) {
			//Trank = max(Trank, r[i]);
			if (Trank < r[i]) {
				Trank = r[i];
				Tpos = i;
			}
		}
	}
	
	if (Trank != -1)
		cout << Tpos;
	else
		cout << Fpos;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}
