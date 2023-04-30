#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n, m;
const LL P = 1e9 + 7;


void solve() {
	cin >> n >> m;
	int maxv = 0, minv = 0;
	for (int i = 1; i <= n; ++i) {
		string s;
		cin >> s;
		int cnt = 0;
		for (auto& c : s) {
			cnt += (c == '1');
		}
		
		LL pi = 0;
		for (int i = 0; i < s.size() - 1; ++i) {
			if (s[i] == '1' && s[i + 1] == '1') {
				pi++;
				i++;
			}
		}
		minv += cnt - min(pi, m / 4);	
		
		pi = 0;
		for (int i = 0; i < s.size() - 1; ++i) {
			if (s[i] == '0' || s[i + 1] == '0') {
				pi++;
				i++;
			}
		}
		maxv += cnt - (m / 4 - min(pi, m / 4));
	}


	cout << minv << ' ' << maxv << '\n'; 
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}
