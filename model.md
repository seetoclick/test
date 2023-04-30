## 树
### 树状数组
```C++
const int N = 114514;
int b[N];   //b[i] = a[i - lowbit(i)] + ... + a[i]

/*lowbit: 
 *参数x: 
 *返回值: 返回输入字符的编号 
 */
int lowbit(int x) {
	return x & (-x);
}

/*lowbit: 
 *参数i: 第i个位置， k：加上k
 *无返回值 
 */
void add(int i, int k) {
	while(i <= n) {
		b[i] += k;
		i += lowbit(i);
	}
}

/*sum: 求[1, i]位置上的和 
 *参数i: 第i个位置 
 *返回值: 返回输入字符的编号 
 */
int sum(int i) {
	int sum = 0;
	while(i) {
		sum += b[i];
		i -= lowbit(i);
	}
	return sum;
}
```
### 线段树
```C++
const int N = 1e5 + 1;
int n, m, a[N];
long long t[N << 2], lazy[N << 2];

void build(int p = 1, int l = 1, int r = n) {	//构建线段树
	if (l == r) {
		t[p] = a[l];
		return;
	}
	
	int mid = (l + r) / 2;
	build(2 * p, l, mid);
	build(2 * p + 1, mid + 1, r);
	t[p] = t[2 * p] + t[2 * p + 1];
}

long long query(int x, int y, int p = 1, int l = 1, int r = n) {
	if (x <= l && r <= y)	//询问区间包括待查区间
		return t[p];
	
	int mid = (l + r) / 2;
	if (lazy[p]) {			//将懒标记下传一层

		t[2 * p] += lazy[p] * (mid - l + 1);	
		lazy[2 * p] += lazy[p];										
		t[2 * p + 1] += lazy[p] * (r - mid);
		lazy[2 * p + 1] += lazy[p];			
		lazy[p] = 0;
	}
	long long ans = 0;
	if (x <= mid) ans += query(x, y, 2 * p, l, mid);		//向左子树查询 wrong query(x, mid, 2 * p, l, mid)
	if (y > mid)  ans += query(x, y, 2 * p + 1, mid + 1, r);//向右子树查询   
	return ans;
}

void update(int d, int x ,int y, int p = 1, int l = 1, int r = n) {
	if (x <= l && r <= y) {		//更新区间包括待查区间，停止向下
		t[p] += d * (r - l + 1);
		lazy[p] += d;
		return;
	} 
	
	int mid = (l + r) / 2;	
	if (lazy[p]) {			//将懒标记下传一层

		t[2 * p] += lazy[p] * (mid - l + 1);
		lazy[2 * p] += lazy[p];									
		t[2 * p + 1] += lazy[p] * (r - mid);
		lazy[2 * p + 1] += lazy[p];			
		lazy[p] = 0;
	}	
	if (x <= mid) update(d, x, y, 2 * p, l, mid);			//向左子树更新	
	if (y > mid) update(d, x, y, 2 * p + 1, mid + 1, r);	//向右子树更新
	t[p] = t[2 * p] + t[2 * p + 1];
}
```
### 珂朵莉树
```C++
struct node
{
    ll l, r;
    mutable ll v; // 这里mutable要写不然可能会CE
    node(ll l, ll r, ll v) : l(l), r(r), v(v) {} // 构造函数
    bool operator<(const node &o) const { return l < o.l; } // 重载小于运算符
};
set<node> tree;

auto split(ll pos)
// 若不支持C++14，auto须改为set<node>::iterator
{
    auto it = tree.lower_bound(node(pos, 0, 0)); // 寻找左端点大于等于pos的第一个节点
    // 若不支持C++11，auto须改为set<node>::iterator
    if (it != tree.end() && it->l == pos) // 如果已经存在以pos为左端点的节点，直接返回
        return it;
    it--; // 否则往前数一个节点
    ll l = it->l, r = it->r, v = it->v;
    tree.erase(it); // 删除该节点
    tree.insert(node(l, pos - 1, v)); // 插入<l,pos-1,v>和<pos,r,v>
    return tree.insert(node(pos, r, v)).first; // 返回以pos开头的那个节点的迭代器
                                               // insert默认返回值是一个pair，第一个成员是我们要的
}

void assign(ll l, ll r, ll v)
{
    auto end = split(r + 1), begin = split(l); // 顺序不能颠倒，否则可能RE
    tree.erase(begin, end); // 清除一系列节点
    tree.insert(node(l, r, v)); // 插入新的节点
}
```
### 字典树
```C++
const int N = 3000009;
char s[N];
int t, n, q, ch[N][65], cnt[N], idx;

/*f: 将字符转化为数字，用于给数值编号
 *参数c: 要转化的字符
 *返回值: 返回输入字符的编号 
 */
int f(char c) {
	int rel;
	if (c >= 'a' && c <= 'z')
		rel = c - 'a' + 1;
	else if (c >= 'A' && c <= 'Z')
		rel = c - 'A' + 27;
	else if (c >= '0' && c <= '9')
		rel = c - '0' + 55;
	return rel;
}

/*insert: 将字符穿插入已构建的字典树
 *参数s: 要插入的字符串
 *无返回值 
 */
void insert(char s[]) {
    int p = 0;
    for (int i = 0; s[i]; i++) {
        int j = f(s[i]);
        if (!ch[p][j])
            ch[p][j] = ++idx;
        p = ch[p][j];
        cnt[p]++;
    }
}

/*query: 查询字符串在字典树中出现次数
 *		 (所谓出现就是作为某个字符串的前缀）
 *参数c: 要查询的字符串
 *返回值: 返回输入字符出现次数 
 */
int query(char s[]) {
    int p = 0;
    for (int i = 0; s[i]; i++) {
        int j = f(s[i]);
        if (!ch[p][j])
            return 0;
        p = ch[p][j];
    }
    return cnt[p];    
}

```
## 数论
### 拓展欧几里得
```C++
/*exgcd: 求不定方程ax + by = (a, b)的一组解 
 *参数a, b:系数 x, y:解 
 *无返回值
 */
void exgcd(ll a, ll b, ll& x, ll& y) {
	if (b == 0) {
		x = 1;
		y = 0;
	}
	else {
		exgcd(b, a % b, x, y);
		ll z = x;
		x = y;
		y = z - y * (a / b);
	}
}
```
### 逆元
#### 问题一：求解 x, 使得 $a * x \equiv 1 (mod\ p)$
##### 模数p为素数时
$x = qpow(a, p - 2)$，  其中qpow(a, x)是利用快速幂求$a^x$ 
##### 模数p不一定为素数时
调用函数exgcd(a, p, x, y), 其中exgcd(a, b, x, y)为拓展欧几里得
#### 问题二：求 1 ~ n 的逆元，其中要求模数p为素数, 且 p > n 
```C++ 
/*inv[i]: i关于p的逆元
 */
inv[1] = 1;
for (int i = 2; i <= n; ++i) {
    int k = p / i,  // p = k * i + r
        r = p % i;      
    inv[i] = (p - k) * inv[r] % p;    //inv[i] = -k * inv[r], 加上p保证式子大于0
}
```
#### 问题三：求 1 ~ n阶乘的逆元，其中要求模数p为素数, 且 p > n 
```C++
fact[0] = 1;
for (int i = 1; i <= n; ++i) 
    fact[i] = fact[i - 1] * i % P;
inv[n] = Inv(fact[n]), inv[0] = 1;
for (int i = n; i >= 2; --i)
    inv[i - 1] = inv[i] * i % P;
```
### 中国剩余定理 
```C++
求同余方程组 x ≡ b[i] (mod a[i]) i = 1,2,...,n (其中a[i]两两互质)

/*M = a[1]*a[2]*...a[n]
 *m[i] = M / a[i]
 *t[i] : m[i]关于a[i]的逆元
 *ans = Σ b[i] * m[i] * t[i]
 */
for (int i = 1; i <= n; ++i) {
    m[i] = M / a[i];
    exgcd(m[i], a[i], t[i], tmp);   //求m[i]关于a[i]的逆元
    t[i] = (t[i] + a[i]) % a[i]; 	
    ans += b[i] * m[i] * t[i];
}
```

$\phi$





















