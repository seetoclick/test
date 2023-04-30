#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int t, n;

void solve() {
	 cin >> n;
	 while (n--) {
		 int x;
		 cin >> x;
		 if (x % 2 == 0)
			 cout << x << ' ';
	 }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}
