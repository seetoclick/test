#include<bits/stdc++.h>
using namespace std;

int  t, n, a[200005];

void solve() {
	cin >> n;
	
	int cntt = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i])
			cntt++;		
	}

	if (cntt & 1) {
		cout << "-1\n";
	}
	else {
		int cnt = 0;
		int ok = 0;
		int l[200005], r[200005];
		int L = 1, R = 0;
		for (int i = 1; i <= n; ++i) {
			if (ok == cntt) {
				cnt++;
				l[cnt] = i;
				r[cnt] = n;
				break;
			}
				
			while (a[i] == 0 && i <= n) i++;
			L = i;
			i++;
			while (a[i] == 0) i++;
			i++;
			
			int tempR = i - 1;
			while (a[i] == 0 && i <= n) i++;
			i--;
			R = i;
			ok += 2;
			cout << L << ' ' << R << '\n';
			
			if (a[L] != a[tempR - 1]) {
				cnt++;
				l[cnt] = L, r[cnt] = tempR - 1;
				cnt++;
				l[cnt] = tempR, r[cnt] = R;
			}
			else {
				if (((tempR - L) & 1) == 0) {
					cnt++;
					l[cnt] = L, r[cnt] = L;
					cnt++;
					l[cnt] = L + 1, r[cnt] = R;
				}
				else {
					cnt++;
					l[cnt] = L, r[cnt] = R;
				}
			}
		}
		
		cout << cnt << '\n';
		for (int i = 1; i <= cnt; ++i) {
			cout << l[i] << ' ' << r[i] << '\n';
		}
	}
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