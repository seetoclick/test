#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int t, n;
string s;

void solve() {
	cin >> n >> s;
	int pos, pos1 = -1, pos2 = -1;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '*')
			pos = i;
		else if (s[i] == '|' && pos1 == -1)
			pos1 = i;
		else if (s[i] == '|' && pos2 == -1)
			pos2 = i;
	}
	
	if (pos > pos1 && pos < pos2)
		cout << "in";
	else
		cout << "out";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}
