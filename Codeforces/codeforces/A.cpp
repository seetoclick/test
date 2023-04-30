#include<bits/stdc++.h>
using namespace std;

int  t, n;

void solve() {
	cin >> n;
	string s;
	cin >> s;
	int cntq = 0, cnta = 0;
	for (int i = 0; i < (int)s.size(); ++i) {
		if (s[i] == 'Q') {
			cntq++;			
		}
		else {
			cnta++;	
			if (cntq > 0)
				cntq--;				
		}
	}
	if (cntq > 0) 
		cout << "No\n";
	else
		cout << "Yes\n";
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