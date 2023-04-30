#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int n, m, a[N + 5], t[4 * N + 5], lazy[4 * N + 5];

void build(int p = 1, int l = 1, int r = n) {
	if (l == r) {
		t[p] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(2 * p, l, mid);
	build(2 * p + 1, mid + 1, r);
	t[p] = t[2 * p] + t[2 * p + 1];
}

void pushdown(int p, int l, int r) {
	if (l == r) return;
	int mid = (l + r) / 2;
	t[2 * p] += (mid - l + 1) * lazy[p];
	t[2 * p + 1] += (r - mid) * lazy[p];
	lazy[2 * p] += lazy[p]; 
	lazy[2 * p + 1] += lazy[p];
	lazy[p] = 0;
}

void update(int L, int R, int k, int p = 1, int l = 1, int r = n) {
	if (L <= l && r <= R) {
		t[p] = (R - L + 1) * k;
		lazy[p] += k;
		return;
	}
	//pushdown(p, l, r);
	int mid = (l + r) / 2;
	if (L <= mid)
		update(L, R, k, 2 * p, l, mid);
	if (R > mid)
		update(L, R, k, 2 * p + 1, mid + 1, r);
	t[p] = t[2 * p] + t[2 * p + 1];
}

int query(int L, int R, int p = 1, int l = 1, int r = n) {
	if (L <= l && r <= R) {
		return t[p];
	}
	pushdown(p, l, r);
	int mid = (l + r) / 2, rel = 0;
	if (L <= mid)
		rel += query(L, R, 2 * p, l, mid);
	if (R > mid)
		rel += query(L, R, 2 * p + 1, mid + 1, r);
	return rel;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	build();
	
	while (m--) {
		int op, L, R;
		cin >> op >> L >> R;
		if (op == 1) {
			int k;
			cin >> k;
			update(L, R, k);
		}
		else {
			cout << query(L, R) << '\n';
		}
	}
	
	return 0;
}
