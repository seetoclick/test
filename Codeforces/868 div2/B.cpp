#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL t, n, k;
const LL P = 1e9 + 7;

void solve() {
	cin >> n >> k;
	vector<int> p(n), pos(n);
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
		p[i]--;
		pos[p[i]] = i;
	}
	
	int need = 0;
	vector<int> wa;
	for (int i = 0; i < n; ++i) {
		if ((pos[i] - i) % k != 0) {
			need++;	
			wa.push_back(i);
		}
		if (need > 2)
			break;
	}
	if (need > 2) {
		cout << "-1\n"; 
	} else if (need == 0) {
		cout << "0\n";
	} else {
		int id1 = wa[0];
		int id2 = wa[1];//cout << id1 << ' '<< id2 << '\n';
		swap(pos[id1], pos[id2]);
		if ((pos[id1] - id1) % k == 0 && (pos[id2] - id2) % k == 0)
			cout << "1\n";
		else
			cout << "-1\n";
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
