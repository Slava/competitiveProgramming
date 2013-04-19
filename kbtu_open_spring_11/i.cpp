#include <cstdio>
#include <cstdlib>
int n, m, a[19], b[19], u[19], c;
void go(int );
void dfs(int , int );
int main ()
{
    freopen("glasswares.in", "r", stdin);
    freopen("glasswares.out", "w", stdout);
    int i, s = 0;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		s += a[i];
	}
	for (i = 1; i <= m; i++) {
		scanf("%d", &b[i]);
		s -= b[i];
	}
	if (s != 0) {
		puts("NO");
		return 0;
	}
	go(1);
 	puts("NO");
	return 0;
}
void dfs(int v, int s, int k) {
	if (k > n) {
		if (s == b[v])
			go(v + 1);
	}
	else {
		dfs(v, s, k + 1);
		if (u[k] == 0)
			if (s + a[k] <= b[v]) {
				u[k] = 1;
				dfs(v, s + a[k], k + 1);
				u[k] = 0;
			}
	}
}
void go(int v) {
	int i;
	if (v > m) {
		puts("YES");
		exit(0);
	}
	else
		dfs(v, 0, 1);
}
