#include<bits/stdc++.h>
using namespace std;

const double PI = acos(-1);
const int N = 8;
int n, t;
int Q[10][10], M[10][10];
double A[10][10];

void f(int& x, int& y) {
	if ((x + y) % 2 == 0) {
		if (x == 1 && y != N) {
			y++;
		} else if (y == N) {
			x++;	
		} else {
			x--;
			y++;
		}
	} else {
		if (y == 1 && x != N) {
			x++;
		} else if (x == N) {
			y++;	
		} else {
			x++;
			y--;
		}
	}
}

double g(int i) {
	if (i == 1)
		return sqrt(0.5);
	return 1;
}

double Round(double x) {
	double t = round(x);
	if (t >= 255)
		return 255;
	else
		return t;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 1; i <= 8; ++i) {
		for (int j = 1; j <= 8; ++j) {
			cin >> Q[i][j];
		}
	}
	cin >> n >> t;
	int i = 1, j = 1;
	while (n--) {
		int x;
		cin >> x;
		M[i][j] = x;
		f(i, j);//cout << i << ' ' << j << '\n';
	}
	
	if (t == 0) {
		for (int i = 1; i <= 8; ++i) {
			for (int j = 1; j <= 8; ++j) {
				cout << M[i][j] << ' ';
			}
			cout << '\n';
		}		
		return 0;
	}	
	
	for (int i = 1; i <= 8; ++i) {
		for (int j = 1; j <= 8; ++j) {
			M[i][j] = M[i][j] * Q[i][j];
		}
	}

	if (t == 1) {
		for (int i = 1; i <= 8; ++i) {
			for (int j = 1; j <= 8; ++j) {
				cout << M[i][j] << ' ';
			}
			cout << '\n';
		}		
		return 0;
	}
	
	for (int i = 1; i <= 8; ++i) {
		for (int j = 1; j <= 8; ++j) {
			for (int x = 1; x <= 8; ++x) {
				for (int y = 1; y <= 8; ++y) {
					A[i][j] += 0.25 * g(x) * g(y) * M[x][y] * cos((i - 0.5) * (x - 1) / 8 * PI) * cos((j - 0.5) * (y - 1) / 8 * PI);
				}
			}
			A[i][j] = Round(A[i][j] + 128);
		}
	}
	
	for (int i = 1; i <= 8; ++i) {
		for (int j = 1; j <= 8; ++j) {
			cout << A[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
