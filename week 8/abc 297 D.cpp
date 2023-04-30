#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL a, b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	LL cnt = 0;
	cin >> a >> b;
	while (a != b) {
		if (a < b)
			swap(a, b);
		if (a % b == 0) {
			cnt += a / b - 1;
			break;
		} else {
			LL k = a / b;
			cnt += k;
			a = a - b * k;
		}
	}
	cout << cnt;
	
	return 0;
}
