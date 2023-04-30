#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const LL P = 1e9 + 7;
const int N = 1000;
LL n, l, r, z;
LL C[N + 5][N + 5], dp[62][N];
int A[62], cnt;

void init() {
	C[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; ++j)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % P;
	}
}

LL dfs(int pos, int num) {
	if (pos < 0)
		return 1;
	if (dp[pos][num] != -1)
		return dp[pos][num];
	
	LL res = 0;
	int lim = num, fre = n - lim;
	if (A[pos] == 0) {
		for (int i = 0; i <= fre; ++i) {
			if ((z & (1LL << pos)) == (i % 2))
				res = (res + C[fre][i] * dfs(pos - 1, lim)) % P;				
		}
	} else {
		for (int i = 0; i <= fre; ++i)
			for (int j = 0; j <= lim; ++j) {
				if ((z & (1LL << pos)) == ((i + j) % 2))
					res = (res + C[fre][i] * C[lim][j] % P * dfs(pos - 1, j)) % P;			
		}
	}
	cout << pos << ' ' << num << ' ' << res << '\n';
	dp[pos][num] = res;
	return res;
}

LL solve(LL x) {
	if (x == 0)
		return 0;
	memset(dp, -1, sizeof(dp));
	cnt = -1;
	while (x) {
		A[++cnt] = x % 2;
		x /= 2;
	}
	return dfs(cnt, n);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> l >> r >> z;
	init();	
	cout << (solve(r) + P - solve(l - 1)) % P;
	
	return 0;
}
