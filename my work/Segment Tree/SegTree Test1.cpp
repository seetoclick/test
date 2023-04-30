#include <bits/stdc++.h>
using namespace std;

double MaxRadio = 1.0;
int n, MaxIndex = 1;

void build(int p, int l, int r) {
	if (l == r) {
		MaxIndex = max(p, MaxIndex);
		return;
	}
	else {
		int mid = (l + r) / 2;
		build(2 * p, l, mid);
		build(2 * p + 1, mid + 1, r);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	//freopen("out.txt", "w", stdout);
	
	for (n = 1; n <= 50000; ++n) {
		MaxIndex = 1;
		build(1, 1, n);
		MaxRadio = max(MaxRadio, 1.0 * MaxIndex / n);
//		cout << "n: " <<n << ' ' << "MaxIndex: " << MaxIndex << ' ' << "Radio: " << 1.0 * MaxIndex / n << '\n';		
		//cout << 1.0 * MaxIndex / n << '\n';	
	}
	
	cout << "比值最大为" <<MaxRadio;
	return 0;
}
