#include <bits/stdc++.h>
using namespace std;

int q, P, n;
long long f[500001], C[3001][3001];

void pre() {
	f[0] = f[1] = 1;
	for (int i = 2; i <= 200000; ++i)
		f[i] = f[i - 1] * (3 * i - 2) * (3 * i - 1) * (3 * i) / 6 / i % P;
	
	C[1][0] = C[1][1] = 1;
	for (int i = 2; i <= 3000; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (j == 0)
				C[i][j] = 1;
			else
				C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % P;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> q >> P;	
	pre();
	
	while (q--) {
		cin >> n;
		if (n == 2 || n == 1)
			cout <<"1\n";
		else if (n % 3 == 0)
			cout << f[n / 3] << '\n';
		else {
			long long ans = 0;
			for (int i = 0; i <= (n - 4) / 3; ++i)
				ans = (ans + ((C[n][3 * i] * f[i]) % P * (n - 3 * i)) % P);
			ans = (ans + (C[n][(n - 1) / 3 * 3] * f[(n - 1) / 3]) % P) % P;
			cout << ans << '\n'; 
		}
	}
	
	return 0;
}