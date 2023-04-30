#include <bits/stdc++.h>
using namespace std;

const int N = 1e4;
int T, n, q, k;
int a[N + 7], cnt;

struct lb{
	int d[30] = {0};
	
	void clear(){
		memset(d, 0, sizeof d);
		cnt = 0;
	}
	
	void print() {
		for (int i = 0; i <= 3; ++i) {
			cout << bitset<3>(d[i]) << '\n';
		}
	}
	
	void add(int x) {
		for (int i = 30; i >= 0; --i) {
			if (x & (1 << i)) {
				if (d[i]) {
					x ^= d[i];
				} else {
					d[i] = x;
					return;
				}
			}
		}
	}
	
	int qmax(){
		int rel = 0;
		for (int i = 30; i >= 0; --i) {
			//			if ((k & (1 << i)) == 0 && rel ^ d[i] > rel)
			//				rel ^= d[i];
			rel = max(rel, rel ^ d[i]);
		}
		return k | rel;
	}
};

lb t[N << 2 + 7];

lb merge(lb t1, lb t2){
	lb rel = t1;
	for (int i = 30; i >= 0; --i) {
		rel.add(t2.d[i]);
	}
	return rel;
}

void build(int p = 1, int l = 1, int r = n){
	if (l == r){
		t[p].add(a[l]);
		return;
	}
	
	int mid = (l + r) / 2;
	build(2 * p, l, mid);
	build(2 * p + 1, mid + 1, r);
	t[p] = merge(t[2 * p], t[2 * p + 1]);
}

lb query(int L, int R, int p = 1, int l = 1, int r = n){
	if (L <= l && r <= R) {
		//cout << p << '\n';
		//t[p].print();
		return t[p];		
	}
	
	
	int mid = (l + r) / 2;
	lb rel;
	rel.clear();
	if (L <= mid) 
		merge(rel, query(L, R, 2 * p, l, mid));
	else if (mid <= R) 
		merge(rel, query(L, R, 2 * p + 1, mid + 1, r));
	return rel;
	
}

int main(){

	cin >> n;
	for (int i = 1; i <= N * 4; ++i)
		t[i].clear();
	
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	build();
	
	lb rel = t[2];
	rel.print();
	cout << '\n';
	t[2].print();
	cout << '\n';
	t[2] = t[1];
	t[2].print();
	cout << '\n';
	
	return 0;
}
