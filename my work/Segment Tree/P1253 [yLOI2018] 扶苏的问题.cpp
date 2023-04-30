#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6;
int n, q, a[N + 9], lazy2[4 * N + 9];
ll t[N * 4 + 9], lazy1[N * 4 + 9];

void build(int p = 1, int l = 1, int r = n) {
	if (l == r) {
		t[p] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(2 * p, l, mid);
	build(2 * p + 1, mid + 1, r);
}

void pushdown(int p = 1, int l = 1, int r = n) {
	if (l == r)
		return;
	lazy1[2 * p] += lazy1[p];
	lazy1[2 * p + 1] += lazy1[p];
	int mid = (l + r) / 2;
	t[2 * p] += (mid - l + 1) * lazy1[p];
	t[2 * p] += (r - mid + 1) * lazy1[p];
	lazy1[p] = 0;
}

ll add(int L, int R, int p = 1, int l = 1, int r = n) {
	if (L <= l && r <= R) {
		return t[p];
	}	
	pushdown(p, l, r);
	int mid = (l + r) / 2;
	ll rel = 0;
	if (mid <= R)
		rel += add(L, R, 2 * p, l, mid);
	if (R <= mid)
		rel += add(L, R, 2 * p, mid + 1, r);
	return rel;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	build();
	
	int op, l, r, x;
	while (q--) {
		cin >> op;
		if (op == 1) {
			cin >> l >> r >> x;

		} else if (op == 2) {
			cin >> l >> r >> x;
			add(l, r, x);			
		} else {
			cin >> l >> r;
		}
	}
	
}
