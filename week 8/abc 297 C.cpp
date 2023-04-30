#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int h, w;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> h >> w;
	for (int i = 1; i <= h; ++i) {
		string s;
		cin >> s;
		for (int i = 0; i < w - 1; ++i) {
			if (s[i] == 'T' && s[i + 1] == 'T') {
				s[i] = 'P', s[i + 1] = 'C';
			}
		}
		cout << s << '\n';
	}
	
	return 0;
}
