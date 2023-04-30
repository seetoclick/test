#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int n, L, R, a[200009], sg[200009];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> L >> R;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		sg[i] = a[i] % (L + R) / L;
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		ans ^= sg[i];
	
	if (ans)
		cout << "First";
	else
		cout << "Second";
	
	return 0;
}
