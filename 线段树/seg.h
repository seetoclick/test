#include <bits/stdc++.h>
using namespace std;

template <class S, S(*op)(S, S), S(*e)()> 
struct SegmentTree {
	int n;
	vector<S> t;
	vector<S> lazy;
	
	SegmentTree (int size_t) {
		n = size_t;
		t = vector<S>(4 * n + 5, e());
	}
	
	SegmentTree (const vector<S> &a) {
		n = a.size();
		t = vector<S>(4 * n + 5, e());
		lazy = vector<S>(4 * n + 5, e());		
		build(1, 1, n);
	}
	
	void build(int p, int l, int r, const vector<S> &a) {
		if (l == r) {
			t[p] = a[l];
			return;
		} else {
			int mid = (l + r) / 2;
			build(2 * p, l, mid);
			build(2 * p + 1, mid + 1, r);
			t[p] = op(t[2 * p], t[2 * p + 1]);
		}		
	}

	void push_up(int p, int l, int r) {
		if (lazy[p]) {
			int mid = (l + r) / 2;
			t[2 * p] = op(t[2 * p], lazy[p] * (mid - l + 1));
			lazy[2 * p] 
		}
	}	
	
	S query(int L, int R, int p = 1, int l = 1, int r = n) {
		if (L <= l && r <= R)
			return t[p];
		int mid = (l + r) / 2;
		if (lazy[p])
	}
	
	long long query(int x, int y, int p = 1, int l = 1, int r = n) {
		if (x <= l && r <= y)	//询问区间包括待查区间
			return t[p];
		
		int mid = (l + r) / 2;
		if (lazy[p]) {			//将懒标记下传一层
			
			t[2 * p] += lazy[p] * (mid - l + 1);	//wrong lazy[2 * p] = lazy[p]
			lazy[2 * p] += lazy[p];					//wrong 反了					
			t[2 * p + 1] += lazy[p] * (r - mid);
			lazy[2 * p + 1] += lazy[p];			
			lazy[p] = 0;
		}
		long long ans = 0;
		if (x <= mid) ans += query(x, y, 2 * p, l, mid);		//向左子树查询 wrong query(x, mid, 2 * p, l, mid)
		if (y > mid)  ans += query(x, y, 2 * p + 1, mid + 1, r);//向右子树查询   
		//cout << l << ' ' << r << ' ' << ans << '\n';
		return ans;
	}	
};
