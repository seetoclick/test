#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t = 1, n;
//SUN，MON，TUE，WED，THU，FRI，SAT
void solve() {
	string s;
	cin >> s;
	
	if (s == "MON")
		cout << 6;
	else if (s == "TUE")
		cout << 5;
	else if (s == "WED")
		cout << 4;
	else if (s == "THU")
		cout << 3;
	else if (s == "FRI")
		cout << 2;
	else if (s == "SAT")
		cout << 1;
	else if (s == "SUN")
		cout << 7;	
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
