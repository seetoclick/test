#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
bool ok[100009] = {0};
string s[100009], t[100009];
map<string, int> mp;

bool dfs(int i) {
	if (ok[i])	//i-th string has changed
		return true;
	else {
		ok[i] = true;
		int j = mp[t[i]];	//if t[i] is same with some s[j]
		if (!j) {
			mp[s[i]] = 0; //change i-th string
			//cout << s[i] << " has been released\n";
			return true;			
		}
		if (ok[j])
			return false;
		else {
			if (dfs(j)) {
				mp[s[i]] = 0;
				//cout << s[i] << " has been released\n";
				return true;				
			}
			else	
				return false;
		}
	}
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i] >> t[i];
		mp[s[i]] = i;
	}
	
	for (int i = 1; i <= n; ++i) {
		if (dfs(i) == false) {
			cout <<"No";
			return;
		}
	}
	cout << "Yes";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}
