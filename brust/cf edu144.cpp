#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const LL P = 998244353;
LL pow2[30], pow3[30], C[30][30], S[30][30];
int t;

int sub(int a, int b) {
	if (a < b)
		return 0;
	else 
		return a - b + 1; 
}

void solve() {
	LL L, R;
	cin >> L >> R;
	int k = log2(R / L);
	cout << k + 1 << ' ';

	int x = R / (1 << k), y = R / (3 * (1 << (k - 1)));
	cout << sub(x, L) + k * sub(y, L) << '\n';		
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
