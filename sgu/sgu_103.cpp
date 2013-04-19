#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std; 

const int N = 310;
int S, T, n, m, r[N], t[2][N], c[N], u[N], a[N][N], d[N], from[N], inf = 1<<30;
int ans[N], k;
char s[2];

bool whichColor(int v, int T) {
	if (T < r[v])
		return c[v];
	T -= r[v];
	T %= t[0][v] + t[1][v];
	return (T >= t[!c[v]][v])^(!c[v]);
}

int nextTime(int v, int T) {
	if (T < r[v])
		return r[v];
	int per = (T-r[v]) / (t[0][v]+t[1][v]),
		rem = (T-r[v]) % (t[0][v]+t[1][v]);
	if (rem < t[!c[v]][v])
		return per * (t[0][v]+t[1][v]) + t[!c[v]][v] + r[v];
	return (per+1) * (t[0][v]+t[1][v]) + r[v];

}

int main() {
	scanf("%d%d%d%d", &S, &T, &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%s%d%d%d", s, r+i, &t[0][i], &t[1][i]);
		c[i] = s[0] == 'P';
	}

	for (int i = 1; i <= m; i++) {
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		a[y][x] = a[x][y] = w;
	}

	for (int i = 1; i <= n; i++)
		d[i] = inf;

	d[S] = 0;
	for (int i = 1; i <= n; i++) {
		int v = 0;
		for (int j = 1; j <= n; j++)
			if (!u[j] && (!v || d[v] > d[j]))
				v = j;
		
		u[v] = 1;
		for (int j = 1; j <= n; j++)
			if (a[v][j]) {
				int time = d[v], left = 9;
				while(whichColor(v,time) != whichColor(j,time) && left--)
					time = min(nextTime(v,time),nextTime(j,time));
				if (left==-1)time = inf;
				time += a[v][j];
				if (time < d[j]) {
					d[j] = time;
					from[j] = v;
				}
			}
	}

	if (d[T] == inf) {
		puts("0");
		return 0;
	}
	printf("%d\n", d[T]);
	int v = T;
	for (; v != 0; v = from[v])
		ans[k++] = v;
	while(k)
		printf("%d ", ans[--k]);
	puts("");

	return 0;
}
