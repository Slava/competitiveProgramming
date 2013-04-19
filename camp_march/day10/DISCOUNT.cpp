#include <cstdio>
#include <algorithm>

const int N = 10100;
int n, a[N], b[N][3];

inline int min (int a, int b, int c, int d = 1 << 30)
{
	int m = a; if (b < m) m = b; if (c < m) m = c; if (d < m) m = d;
	return m;
}

int main ()
{
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf ("%d", a + i);
	std::sort(a + 1, a + n + 1);
	b[1][1] = b[1][2] = b[2][1] = b[2][2] = b[3][2] = 1 << 30;
	for (int i = 1; i <= n; i++)
	{
		b[i][0] = a[i] + min (b[i - 1][0], b[i - 1][1], b[i - 1][2]);
		if (i - 2 > 0)
			b[i][1] = a[i] + a[i - 1] + a[i - 2] - min(a[i], a[i - 1], a[i - 2]) + min(b[i - 3][0], b[i - 3][1], b[i - 3][2]);
		if (i - 3 > 0)
			b[i][2] = a[i] + a[i - 1] + a[i - 2] + a[i - 3] - min(a[i], a[i - 1], a[i - 2], a[i - 3]) + min(b[i - 4][0], b[i - 4][1], b[i - 4][2]);
	}
	printf("%d\n", min(b[n][0], b[n][1], b[n][2]));
	return 0;
}

