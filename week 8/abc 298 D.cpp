#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const LL P = 998244353;
LL POW10[600099];
char s[600099];
int q, L = 1, R = 1;

void solve() {	
	LL ans = 1;
	cin >> q;
	
	POW10[0] = 1;
	for (int i = 1; i <= q; ++i)	
		POW10[i] = (10 * POW10[i - 1]) % P;
		
	s[1] = '1';
	while (q--) {
		int op;
		char x;
		cin >> op;
		if (op == 1) {
			cin >> x;
			s[++R] = x;
			ans = (10 * ans + (x - '0')) % P;
			//cout << ans << '\n';
		} else if (op == 2) {
			int d = s[L] - '0', n = (R - L + 1); //cout << s[L] << ' ';
			ans = ans - d * POW10[n - 1] % P; //cout << ans << '\n';
			ans = (ans + 2 * P) % P; 
			L++;
		} else {
			cout << ans << '\n';
		}
		//cout << s + 1 << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}
