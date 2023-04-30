#include<bits/stdc++.h>
using namespace std;

int n, m;
int X[15], Y[15], P[6], Q[6];
double ans = 114511114511233.0;
double minDis[9000][70];

double dis(int x1, int y1, int x2, int y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int myCount(int N) {
	int cnt = 0;
	while(N) {
		cnt += (N % 2 == 1);
		N /= 2;
	}
	return cnt;
}

void dfs(int now, int N, int M, double t) {
	//cout << now << ' ' << N << ' ' << M << ' ' << t << '\n';
	if (myCount(N) == n) {
		//cout << now << ' ' << N << ' ' << M << ' ' << t << '\n';
		ans = min(ans, t + dis(X[now], Y[now], X[0], Y[0]) / (1 << myCount(M)));
		return;
	}
	
	for (int i = 1; i <= n; ++i) {
		if ((N & (1 << i)) == 0) {
			int tempN = N + (1 << i);
			double tempDis;
			if (now >= 20)
				tempDis = t + dis(P[now - 20], Q[now - 20], X[i], Y[i]) / (1 << myCount(M));
			else
				tempDis = t + dis(X[now], Y[now], X[i], Y[i]) / (1 << myCount(M));				
			if (minDis[tempN][M] > 0 && minDis[tempN][M] < tempDis)
				return;
			else
				minDis[tempN][M] = tempDis;	
			dfs(i, tempN, M, tempDis);
		}
	}
	for (int i = 1; i <= m; ++i) {
		if ((M & (1 << i)) == 0) {
			int tempM = M + (1 << i);
			double tempDis;
			if (now >= 20)
				tempDis = t + dis(P[now - 20], Q[now - 20], P[i], Q[i]) / (1 << myCount(M));
			else
				tempDis = t + dis(X[now], Y[now], P[i], Q[i]) / (1 << myCount(M));
			if (minDis[N][tempM] > 0 && minDis[N][tempM] < tempDis)
				return;
			else
				minDis[N][tempM] = tempDis;			
			dfs(i + 20, N, tempM, tempDis);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)	
		cin >> X[i] >> Y[i];
	for (int i = 1; i <= m; ++i)
		cin >> P[i] >> Q[i];
	
	dfs(0, 0, 0, 0.0);
	cout << fixed << setprecision(10) << ans;
	
	return 0;
}