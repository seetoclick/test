#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t, n;

void solve() {
	cin >> n;
	if (n % 2 == 0) {
		cout << n / 2 << ' ' << n / 2 << '\n';
		return;
	}
	if (n == 9) {
		cout << "4 5\n";
		return;
	}
	int x = n / 2, y = n - n / 2;
	if (n % 10 == 9) {
		int A[15] = {0}, B[15] = {0}, cnt = 0, Sa = 0, Sb = 0;
		int m = n;
		while (n) {
			A[++cnt] = n % 10;
			n /= 10;
		}
		for (int i = 1; i < cnt; ++i) {
			B[i] = A[i];
			A[i] = 0;
			Sb += B[i];
		}
		Sa = A[cnt];
		int d = Sb - Sa + 1;
		for (int i = 1; i < cnt; ++i) {
			//cout << i << '\n';
			if (2 * B[i] < d) {
				d -= 2 * B[i];
				swap(A[i], B[i]);
			} else  {
				A[i] = d / 2;
				B[i] -= d / 2;
				break;
			}
		}
		
		x = 0, y = 0;
		for (int i = cnt; i >= 1; --i) {
			//cout << x << ' '<< y << '\n';
			x = 10 * x + A[i];
			y = 10 * y + B[i];
		}
	}
	
	cout << x << ' ' << y << '\n';
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
