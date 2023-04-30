#include <bits/stdc++.h>
using namespace std;
using LL = long long;

struct SegmentTree {
	int n;	
	vector<double> t1, t2;
	vector<double> lazy;
	
	SegmentTree(int size_t) {
		n = size_t;
		t1 = vector<double>(4 * n + 5, 0);
		t2 = vector<double>(4 * n + 5, 0);		
	}
	
	SegmentTree(const vector<double> &a) {
		n = a.size() - 1;
		t1 = vector<double>(4 * n + 5, 0);
		t2 = vector<double>(4 * n + 5, 0);		
		lazy = vector<double>(4 * n + 5, 0);		
		build(1, 1, n, a);
	}
	
	void build(int p, int l, int r, const vector<double> &a) {
		if (l == r) {
			t1[p] = a[l];
			t2[p] = a[l] * a[l];//cout << p << ' ' << l << ' ' << r << ' ' << t2[p] << '\n';
			return;
		} else {
			int mid = (l + r) / 2;
			build(2 * p, l, mid, a);
			build(2 * p + 1, mid + 1, r, a);
			t1[p] = t1[2 * p] + t1[2 * p + 1];
			t2[p] = t2[2 * p] + t2[2 * p + 1];		//cout << p << ' ' << l << ' ' << r << ' ' << t2[p] << '\n';
		}		
	}
	
	void push_down(int p, int l, int r) {
		if (lazy[p]) {
			int mid = (l + r) / 2;
			t2[2 * p] += 2 * lazy[p] * t1[2 * p] + (mid - l + 1) * lazy[p] * lazy[p];
			t1[2 * p] += lazy[p] * (mid - l + 1);
			lazy[2 * p] += lazy[p];
			
			t2[2 * p + 1] += 2 * lazy[p] * t1[2 * p + 1] + (r - mid) * lazy[p] * lazy[p];
			t1[2 * p + 1] += lazy[p] * (r - mid);			
			lazy[2 * p + 1] += lazy[p];
			
			lazy[p] = 0;
		}
	}	
	
	double query1(int L, int R, int p, int l, int r) {
		if (L <= l && r <= R)
			return t1[p];
		push_down(p, l, r);
		int mid = (l + r) / 2;
		double ans = 0;
		if (L <= mid)
			ans += query1(L, R, 2 * p, l, mid);
		if (R > mid)
			ans += query1(L, R, 2 * p + 1, mid + 1, r);
		return ans;
	}
	
	double query1(int L, int R) {
		return query1(L, R, 1, 1, n);
	}

	double query2(int L, int R, int p, int l, int r) {
		if (L <= l && r <= R)
			return t2[p];
		push_down(p, l, r);
		int mid = (l + r) / 2;
		double ans = 0;
		if (L <= mid)
			ans += query2(L, R, 2 * p, l, mid);
		if (R > mid)
			ans += query2(L, R, 2 * p + 1, mid + 1, r);
		return ans;
	}
	
	double query2(int L, int R) {
		return query2(L, R, 1, 1, n);
	}	
	
	void update(double k, int L, int R, int p, int l, int r) {
		if (L <= l && r <= R) {
			t2[p] += 2 * k * t1[p] + (r - l + 1) * k * k;
			t1[p] += (r - l + 1) * k;
			lazy[p] += k;
			return;
		}
		push_down(p, l, r);
		int mid = (l + r) / 2;
		if (L <= mid)
			update(k, L, R, 2 * p, l, mid);
		if (R > mid)
			update(k, L, R, 2 * p + 1, mid + 1, r);
		t1[p] = t1[2 * p] + t1[2 * p + 1];
		t2[p] = t2[2 * p] + t2[2 * p + 1];
	}
	
	void update(double k, int L, int R) {
		update(k, L, R, 1, 1, n);
	}
};

int n, m;
void solve() {
	freopen("P1471_2.in", "r", stdin);
	freopen("P1471_2_my.out", "w", stdout);
	
	cin >> n >> m;
	vector<double> a(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	SegmentTree seg(a);
	while (m--) {
		int op, l, r;
		cin >> op >> l >> r;
		if (op == 1) {
			double k;
			cin >> k;
			seg.update(k, l, r);			
		} else if (op == 2) {
			cout << fixed << setprecision(4) << 1.0 * seg.query1(l, r) / (r - l + 1) << '\n';
		} else {
			double sum1 = seg.query1(l, r) / (r - l + 1);
			double sum2 = seg.query2(l, r);
			cout << fixed << setprecision(4) << sum2 / (r - l + 1) - sum1 * sum1 << '\n';
		}
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}
