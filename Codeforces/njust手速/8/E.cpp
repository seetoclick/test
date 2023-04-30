#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t, n;
vector<int> pr;

void init() {
	vector<int> isP(4e4, 1);
	for (int i = 2; i <= 4e4; ++i) {
		if (isP[2]) {
			pr.push_back(i);
		}
		for (auto p : pr) {
			if (i * p > 4e4)
				break;
				isP[i * p] == 0;			
			if (i % p == 0) {
				break;
			}		
		}
	}
}

void solve() {
	ll A, B, C;
	cin >> A >> C;
	
	if (C % A != 0) {
		cout << -1 << '\n';
		return;
	}
	
	ll t = C / A;cout << t << ' ';
	ll g = __gcd(A, t);
	for (int j = 0; pr[j] <= A / pr[j]; ++j) {
		if (A % pr[j] == 0) {
			cout << pr[j] * t * g << '\n';
			return;
		}
	}
	cout << A * t * g << '\n'; 
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	init();
	cin >> t;
	while (t--) {
		solve();
	}
	
	return 0;
}
