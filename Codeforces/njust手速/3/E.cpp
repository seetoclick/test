#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t = 1, n, P;
string s;


void solve() {
	cin >> n >> P >> s;
	vector<int> num(n + 1, 0);
	vector<int> mi(n + 1);
	vector<int> tong(P, 0);	
	
	mi[0] = 1;
	for (int i = 1; i < n; ++i)
		mi[i] = (mi[i - 1] * 10) % P;
	num[0] = 0, num[1] = (s[0] - '0') % P;
	for (int i = 2; i <= n; ++i) {
		num[i] = ((s[i - 1] - '0') + 10 * num[i - 1]) % P;
	}
	
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int k = 0; k <= min(P - 1, n - i); k++) {
			int rel = (mi[k] * num[i]) % P;
			int N = (n - i - k) / P + 1;
			if (k == 0)
				N--;
			ans += N;
			cout << i << ' ' << rel << ' ' << N << '\n';
		}		
	}
	


	cout << ans;
	//cout << num[4] << '\n';
//	ll ans = 0;
//	for (int i = 1; i <= n; ++i) {
//		for (int j = 1; j <= i; ++j) {	//[j, i]
//			ll rel = (num[i] - mi[i - j + 1] * num[j - 1] + P) % P;
//			if (rel % P == 0)
//				ans++;
//			//cout << j << ' ' << i << " rel = " << rel << '\n';
//		}
//	}
	

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
