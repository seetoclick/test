#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t, n;
ll a[114]; 

void solve() {
	cin >> n;
	int odd = 0, even = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] % 2 == 0)
			even++;
		else
			odd++;
	}	
	sort(a + 1, a + n + 1);
	bool repeat = false;
	for (int i = 1; i < n; ++i) {
		if (a[i] == a[i + 1])
			repeat = true;
	}
	if (repeat) {
		cout << "NO\n";
		return;
	}
	
	
	for (int i = 2; i <= n; ++i) { //assuming that i is prime
		int cnt[114] = {0};
		for (int j = 1; j <= n; ++j) {
			int r = a[j] % i;
			cnt[r]++;
		}
		bool ok = 0;
		for (int k = 0;k < i; ++k) {	
			if (cnt[k] < 2) {	//exisit x = i - k (mod i)
				ok = 1;
				break;
			}
		}
		if (!ok) {
			cout << "NO\n";
			return;
		}
	}	
	cout << "YES\n";	
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
