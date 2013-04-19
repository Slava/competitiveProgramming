#include <cstdio>
#include <cstdlib>

#define nxt(x) (x|(x+1))
#define prv(x) ((x&(x+1))-1)

const int N = 130;
int n, t[N][N][N];

void inc(int x, int y, int z, int v) {
	for (int i = x; i < n; i = nxt(i))
		for (int j = y; j < n; j = nxt(j))
			for (int k = z; k < n; k = nxt(k))
				t[i][j][k] += v;
}

int sum(int x, int y, int z) {
	int r = 0;
	for (int i = x; i >= 0; i = prv(i))
		for (int j = y; j >= 0; j = prv(j))
			for (int k = z; k >= 0; k = prv(k))
				r += t[i][j][k];
	return r;
}

int sum(int x, int y, int z, int X, int Y, int Z) {
	x--; y--; z--;
	return sum(X,Y,Z) - sum(x,Y,Z) - sum(X,y,Z) - sum(X,Y,z)
		+ sum(X,y,z) + sum(x,Y,z) + sum(x,y,Z) - sum(x,y,z);
}

int main() {
	scanf("%d", &n);
	for (;;) {
		int cmd, x, y, z, X, Y, Z, v;
		scanf("%d", &cmd);
		if (cmd == 3) break;
		if (cmd == 1) {
			scanf("%d%d%d%d", &x, &y, &z, &v);
			inc(x, y, z, v);
		}
		else {
			scanf("%d%d%d%d%d%d", &x, &y, &z, &X, &Y, &Z);
			printf("%d\n", sum(x,y,z,X,Y,Z));
		}
	}
	return 0;
}
