#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int n, k, a[20];
set<LL> st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	st.insert(0);
	for (int i = 1; i <= k; ++i) {
		auto it = st.begin();
		LL value = *it;
		st.erase(it);
		for (int j = 1; j <= n; ++j)
			st.insert(value + a[j]);
	}
	cout << *st.begin();
	
	return 0;
}
