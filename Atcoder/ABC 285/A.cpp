#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;

void solve() {
	int a, b;
	cin >> a >> b;
	if (b == 2 * a || b == 2 * a + 1)
		cout << "Yes";
	else 
		cout << "No";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}
