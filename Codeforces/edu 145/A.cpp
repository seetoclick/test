#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n;
const LL P = 1e9 + 7;


void solve() {
	string s;
	cin >> s;
	
	int cnt = 0;
	map<char, int> mp;
	for (int i = 0; i <= 3; ++i) {
		mp[s[i]]++;
		cnt = max(cnt, mp[s[i]]);
	}
	
	if (cnt == 4)
		cout << "-1\n";
	else if (cnt == 3) 
		cout << "6\n";
	else if (cnt == 1)
		cout << "4\n";
	else
		cout << "4\n";
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
