#include <cstdio>
#include <cmath>

#define min(a,b) ((a)<(b)?(a):(b))

const int N = 100010;
const int logN = 25;
int d[N][logN], p2[N], a[N], n;

inline int query (int l, int r)
{
	int k = p2[r - l + 1];
	return min(d[l][k], d[r - (1 << k) + 1][k]);
}

int main ()
{
	for (int i = 0; i < 10010; i++)
		p2[i] = (int)log2(i);
	scanf ("%d", &n);
	for (int i = 0; i < n; i++)
		scanf ("%d", a + i);
	for (int i = 0; i < n; i++)
		d[i][0] = a[i];
	for (int j = 1; (1 << j) <= n; j++)
		for (int i = 0; i + (1 << j) - 1 < n; i++)
			d[i][j] = min(d[i][j - 1], d[i + (1 << (j - 1))][j - 1]);
	int l, r;
	while (scanf ("%d%d", &l, &r) == 2)
		printf("%d\n", query(l, r));
	
	return 0;
}

