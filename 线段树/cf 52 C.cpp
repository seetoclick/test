#include <bits/stdc++.h>
using namespace std;
using LL = long long;

struct SegmentTree {
	int n;
	vector<long long> t;
	vector<long long> lazy;
	
	using LL = long long;
	
	SegmentTree (int size_t) {
		n = size_t;
		t = vector<long long>(4 * n + 5, 0);
	}
	
	SegmentTree (const vector<long long> &a) {
		n = a.size() - 1;
		t = vector<long long>(4 * n + 5, 0);
		lazy = vector<long long>(4 * n + 5, 0);		
		build(1, 1, n, a);
	}
	
	void build(int p, int l, int r, const vector<long long> &a) {
		if (l == r) {
			t[p] = a[l];
			return;
		} else {
			int mid = (l + r) / 2;
			build(2 * p, l, mid, a);
			build(2 * p + 1, mid + 1, r, a);
			t[p] = t[2 * p] +  t[2 * p + 1];
		}		
	}
	
	void push_down(int p, int l, int r) {
		if (lazy[p]) {
			int mid = (l + r) / 2;
			t[2 * p] = lazy[p] * (mid - l + 1);
			lazy[2 * p] = lazy[p];
			t[2 * p + 1] = lazy[p] * (r - mid);
			lazy[2 * p + 1] = lazy[p];
			lazy[p] = 0;
		}
	}	
	
	long long query(int L, int R, int p, int l, int r) {
		if (L <= l && r <= R)
			return t[p];
		push_down(p, l, r);
		int mid = (l + r) / 2;
		long long ans = 0;
		if (L <= mid)
			ans += query(L, R, 2 * p, l, mid);
		if (R > mid)
			ans += query(L, R, 2 * p + 1, mid + 1, r);
		return ans;
	}
	
	long long query(int L, int R) {
		return query(L, R, 1, 1, n);
	}
	
	void update(long long k, int L, int R, int p, int l, int r) {
		if (L <= l && r <= R) {
			t[p] = (r - l + 1) * k;
			lazy[p] = k;
			return;
		}
		push_down(p, l, r);
		int mid = (l + r) / 2;
		if (L <= mid)
			update(k, L, R, 2 * p, l, mid);
		if (R > mid)
			update(k, L, R, 2 * p + 1, mid + 1, r);
		t[p] = t[2 * p] + t[2 * p + 1];
	}	
	
	void update(long long k, int L, int R) {
		update(k, L, R, 1, 1, n);
	}	
};

int n, q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	vector<LL> a(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	SegmentTree seg(a);
	
	cin >> q;
	while (q--) {
		int l, r;
		LL v;
		cin >> l >> r;
		l++, r++;
		char space = getchar();
		if (space == '\n') {
			if (l <= r)
				cout << seg.query(l, r) << '\n';
			else {
				LL ans1 = seg.query(l, n);
				LL ans2 = seg.query(1, r);
				cout << min(ans1, ans2) << '\n';
			}
		} else {
			cin >> v;
			if (l <= r) 
				seg.update(v, l, r);
			else {
				seg.update(v, l, n);
				seg.update(v, 1, r);
			}
		}
	}
	
	return 0;
}
