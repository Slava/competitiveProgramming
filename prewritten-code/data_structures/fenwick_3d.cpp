#include <cstdio>

const int N = 130;
int t[N][N][N], n;

void add(int x, int y, int z, int d) {
	for (int i = x; i < n; i = i|(i + 1))
		for (int j = y; j < n; j = j|(j + 1))
			for (int k = z; k < n; k = k|(k + 1))
				t[i][j][k] += d;
}

int sum (int x, int y, int z) {
	int r = 0;
	for (int i = x; i >= 0; i = i&(i + 1), i--)
		for (int j = y; j >= 0; j = j&(j + 1), j--)
			for (int k = z; k >= 0; k = k&(k + 1), k--)
				r += t[i][j][k];
	return r;
}

int sum (int x1, int y1, int z1, int x2, int y2, int z2) {
	x1--,y1--,z1--;
	return sum(x2,y2,z2) - sum(x1,y2,z2) - sum(x2,y1,z2) - sum(x2,y2,z1)
			+ sum(x1,y1,z2) + sum(x1,y2,z1) + sum(x2,y1,z1) - sum(x1,y1,z1);
}

int main () {
	int m, x, y, z, x2, y2, z2, f = 0, d;
	scanf ("%d", &n);
	while(!f) {
		scanf ("%d", &m);
		switch (m) {
			case 1:
				scanf ("%d%d%d%d", &x, &y, &z, &d);
				add(x, y, z, d);
				break;
			case 2:
				scanf ("%d%d%d%d%d%d", &x, &y, &z, &x2, &y2, &z2);
				printf ("%d\n", sum(x,y,z,x2,y2,z2));
				break;
			case 3:
				f = 1;
				break;
		}
	}

	return 0;
}

