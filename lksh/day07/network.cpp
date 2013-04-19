#include <cstdio>
#include <cstdlib>
#define bit(x,y) (((x)>>(y))&1)
#define max(a,b) (a>b?a:b)

const int N = 19;
int n, a[N][N], d[1 << N], ans;
char s[20];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", s);
		for (int j = 0; j < n; j++)
			if (s[j] == 'Y')
				a[i][j] = 1;
	}
	for (int i = 0; i < (1 << n); i++) {
		int v = 0;
		for (; v < n; v++)
			if (bit(i, v))
				break;
		for (int j = 0; j < n; j++)
			if (a[v][j] && bit(i,j))
				d[i] = max(d[i], d[i ^ (1 << v) ^ (1 << j)] + 1);
		d[i] = max(d[i], d[i ^ (1 << v)]);
		ans = max(ans, d[i]);
	}
	printf("%d\n", ans * 2);
	return 0;
}
