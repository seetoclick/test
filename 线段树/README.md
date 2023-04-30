# 线段树
## 线段树优化dp
当转移式子为 $dp_i = \displaystyle \min_{j <= i AND check(i, j)} dp_j$ 时，用线段树优化