#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
const int N = 500000;
int cnt[N + 9], dp[N + 9], t[2 * N + 9]; //cnt[i]: 前i个中崇拜yy的人数, dp[i]: 前i个人最少分配的宿舍数, t[i]: 用于树状数组

int lowbit(int x) {
	return x & (-x);
}

int query(int pos) {
	int num = 0;
	for (int i = pos; i >= 1; i -= lowbit(i)) {
		num += t[i];
	}
	return num;
}

void update(int pos, int k) {
	for (int i = pos; i <= n; i += lowbit(i)) {
		t[i] += k;
	}
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		int tmp;
		cin >> tmp;
		cnt[i] = cnt[i - 1] + (tmp == 1);
		update(i - 2 * cnt[i] + N, 0); //避免负下标
	}
	
	dp[1] = 1, cnt[0] = 0;
	for (int i = 2; i <= n; ++i) {
		dp[i] = dp[i - 1] + 1;
		for (int j = 0; j < i - 1; ++j) {
			int yy = cnt[i] - cnt[j]; //编号在[j + 1, i]内是否不会吵
			if (abs(i - j - 2 * yy) <= m || yy == i - j)
				dp[i] = min(dp[i], dp[j] + 1);
		}
		//cout << dp[i] << '\n';
	}
	/*
	  Case1: abs(i - j - 2 * (cnt[i] - cnt[j])) <= m, abs(d[i] - d[j]) <= m, d[i] = i - 2 * cnt[i] 
	  Case2: i - j = cnt[i] - cnt[j], e[i] = e[j]
	 */
	cout << dp[n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}
