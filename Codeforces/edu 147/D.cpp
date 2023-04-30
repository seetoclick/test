#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const LL inf = 1e18;
LL t, n, k;
const LL P = 1e9 + 7;

void solve() {
	cin >> n >> k;
	vector<LL> L(n + 1), R(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> L[i];
	for (int i = 1; i <= n; ++i)
		cin >> R[i];
	
	LL ans = -1, one = 0, more = 0, s = 0;
	for (int i = 1; i <= n; ++i) { //it can be shown that greedly get is best otherwise len = 1
		LL len = R[i] - L[i] + 1;
		if (s + len + one >= k) {
			LL move = 0;		
			if (s + len >= k)
				move = L[i] + k - s - 1 + (more + 1) * 2;	//not choose one
			else 
				move = R[i] + (k - s - len) * 2 + (more + 1) * 2;
			if (ans == -1 || ans > move)
				ans = move;
		}
		
		if (len == 1)
			one++;
		else {
			s += len;
			more++;
		}
		
		if (s >= k)
			break;		
	}
	
	cout << ans << '\n';
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
