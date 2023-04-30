#include <bits/stdc++.h>
using namespace std;

int n;
//int L[20009], R[20009];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	int L, R, x1 = 1, x2 = 1, ans1 = 0, ans2 = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> L >> R;
		int l = 1e9, r = 1e9;

		if (x1 < L) {
			l = min(l, ans1 + R - x1 + R - L);
			r = min(r, ans1 + R - x1); 			
		} else if (x1 > R) {
			l = min(l, ans1 + x1 - L);
			r = min(r, ans1 + x1 - L + R - L);
		} else {
			l = min(l, ans1 + R - x1 + R - L);
			r = min(r, ans1 + x1 - L + R - L);
		}
		
		if (x2 < L) {		
			l = min(l, ans2 + R - x2 + R - L);
			r = min(r, ans2 + R - x2); 			
		} else if (x2 > R) {
			l = min(l, ans2 + x2 - L);
			r = min(r, ans2 + x2 - L + R - L);
		} else {
			l = min(l, ans2 + R - x2 + R - L);
			r = min(r, ans2 + x2 - L + R - L);
		}		
		
		ans1 = l, ans2 = r;//cout << ans1 << ' ' << ans2 << '\n';
		x1 = L, x2 = R;
	}
	
	int ans = min(ans1 + n - x1, ans2 + n - x2);
	cout << ans + n - 1;
	return 0;
}
