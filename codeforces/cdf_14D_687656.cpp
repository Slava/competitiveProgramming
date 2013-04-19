#include <cstdio>
#include <cstdlib>
#include <cstring>

int n, a[210][210], ans, Ans, best;
int max(int i, int j) { return i > j ? i : j; }

int dfs(int v, int p = -1) {
	int best = 0;
	for (int i = 0; i < n; i++)
		if (a[v][i] && i != p)
			best = max(best, dfs(i, v) + 1);
	return best;
}

void dotry(int v, int p = -1) {
	int was = -1;
	for (int i = 0; i < n; i++)
		if (a[i][v]) {
			was++;
			if (i != p)
				dotry(i, v);
		}
	if (!was)
		best = max(best, dfs(v));
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--; y--;
		a[x][y] = a[y][x] = 1;
	}
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i][j]) {
				a[i][j] = a[j][i] = 0;
				best = 0;
				dotry(i); ans = best;
				best = 0;
				dotry(j); ans *= best;
				if (ans > Ans)
					Ans = ans;
				a[i][j] = a[j][i] = 1;
			}
	printf("%d\n", Ans);
	return 0;
}





// lang: GNU C++
// memory: 1500 KB
// author: imslavko
// submit_date: May 19, 2010 8:53:35 PM
// contest: 14
// link: /contest/14/submission/687656
// time: 1390 ms
// verdict: Accepted
// problem: 14D - Two Paths
// ID: 687656
// downloaded by very stupid script
