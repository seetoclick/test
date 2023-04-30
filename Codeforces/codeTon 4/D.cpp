#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n;
const LL P = 1e9 + 7;
LL f(LL a, LL b, LL t) {
	if (t == 0)
		return 0;
	return a * t - b * (t - 1);
}

void solve() {
	int q;
	cin >> q;
	LL L = -1, R = -1;
	while (q--) {
		LL op, a, b, n;
		cin >> op;
		if (op == 1) {
			cin >> a >> b >> n;
			LL tmpL, tmpR;
			if (n == 1) {
				tmpL = 1;
				tmpR = a - 1;
			} else {
				tmpL = f(a, b, n - 1) + 1;
				tmpR = f(a, b, n);
			}
			
			if (L == -1) {
				L = tmpL;
				R = tmpR;
				cout << "1 ";
			} else {
				if (tmpR < L || tmpL > R)
					cout << "0 ";
				else {
					L = max(L, tmpL);
					R = min(R, tmpR);
					if (R - L == 1)
						cout << "1 ";
					else
						cout << "0 ";
				}
			}
		} else {
			cin >> a >> b;//cout << L << ' ' << R << '\n';
			if (L == -1)
				cout << "-1 ";
			else {
				LL tL = max((L - b) / (a - b), (R - b) / (a - b) - 1);
				LL tR = min((L - b) / (a - b) + 1, (R - b) / (a - b));
				int cnt = 0;
				LL ans;//cout << f(a, b, 1) << '\n';
				for (LL i = max(1LL, tL - 5); i <= tR + 5; ++i) {
					if (f(a, b, i - 1) < L && f(a, b, i) >= R) {
						cnt = 1;
						ans = i;
						break;
					}
					if (f(a, b, i - 1) < L && f(a, b, i) >= L && f(a, b, i) <= R && R - L >= 1) {
						cnt = 2;
						ans = i;
						break;
					}					
					if (f(a, b, i) >= L && f(a, b, i) <= R) {
						cnt++;
						if (cnt == 1)
							ans = i;
						else
							break;
					}
				}
				if (cnt != 1)
					cout << "-1 ";
				else
					cout << ans << ' ';
			}
		}
	}
	cout << '\n';
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
