#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t = 1, n, q;
string s;
char ss[200009][2];
int cnt[2], r;

void print() {
	if (r == 0) {
		for (int i = cnt[r]; i >= 1; --i)
			cout << ss[i][r];		
		cout << s;	
		for (int i = 1; i <= cnt[r ^ 1]; ++i)
			cout << ss[i][r ^ 1];
	}
	else {
		for (int i = cnt[r]; i >= 1; --i)
			cout << ss[i][r];		
		for (int i = int(s.size() - 1); i >= 0; --i)
			cout << s[i];
		for (int i = 1; i <= cnt[r ^ 1]; ++i)
			cout << ss[i][r ^ 1];
	}	
}

void solve() {
	cin >> s >> q;
	while (q--) {
		int T;
		cin >> T;
		if (T == 1) {
			r ^= 1; 	//翻转
		} else {
			int F;
			char C;
			cin >> F >> C;
			if (F == 1) {
				cnt[r]++;
				ss[cnt[r]][r] = C;
			} else {
				cnt[r ^ 1]++;
				ss[cnt[r ^ 1]][r ^ 1] = C;
			}
		}//cout << "r: " << r << ' ' << cnt[r] << ' ' << cnt[r ^ 1] << '\n';
		//print();
		//cout << '\n';
	}
	
	print();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	//cin >> t;
	while (t--) {
		solve();
	}
	
	return 0;
}
