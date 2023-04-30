#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int n, q;

void solve() {
	cin >> n >> q;
	vector<map<int, int>> box(n + 1);
	vector<set<int>> card(200009);
	
	while (q--) {
		int op, i, j;
		cin >> op;
		if (op == 1) {
			cin >> i >> j;
			box[j][i]++;
			card[i].insert(j);
		} else if (op == 2) {
			cin >> i;
			for (auto &p : box[i])
				for (int k = 1; k <= p.second; ++k)
					cout << p.first << ' ';
			cout << '\n';
		} else {
			cin >> i;
			for (auto &p : card[i])
				cout << p << ' ';
			cout << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}
