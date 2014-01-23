#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>

const int N = 255;
double inf = 1e10,
	   gr[N][N], w1[N], w2[N], min, ans;
bool was1[N], was2[N];
int from[N], minj, next, i, j, n, pair1[N], pair2[N];

double curgr(int i, int j) {
	return gr[i][j] + w1[i] + w2[j];
}

double dist(int j) {
	return from[j] ? curgr(from[j], j) : inf;
}

void go(int j) {
	was1[j] = 1;
	for (int k = 1; k <= n; k++)
		if (!was2[k] && curgr(j, k) < dist(k))
			from[k] = j;
}

int main() {
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++) {
			double x; scanf("%lf", &x);
			gr[i][j] = x;
		}

	for (i = 1; i <= n; i++) {
		memset(was1, 0, sizeof was1);
		memset(was2, 0, sizeof was2);
		memset(from, 0, sizeof from);
		for (j = 1; j <= n; j++)
			if (!pair1[j])
				go(j);
		while (true) {
			min = inf;
			minj = -1;
			for (j = 1; j <= n; j++)
				if (!was2[j] && dist(j) < min)
					min = dist(j), minj = j;
			for (j = 1; j <= n; j++) {
				if (was1[j])
					w1[j] -= min;
				if (was2[j])
					w2[j] += min;
			}
			was2[minj] = 1;
			if (!pair2[minj])break;
			go(pair2[minj]);
		}
		while (minj != 0) {
			next = pair1[from[minj]];
			pair1[from[minj]] = minj;
			pair2[minj] = from[minj];
			minj = next;
		}
	}
	for (i = 1; i <= n; i++)
		ans -= w1[i] + w2[i];
	printf("%lf\n", exp(-ans));
	for (i = 1; i <= n; i++)
		printf("%d ", pair1[i]);
	return 0;
}
