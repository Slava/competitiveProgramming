#include <cstdio>

int r, c, C[255], i, j, ans;
int main ()
{
	char p, m[200][200];
	scanf ("%d %d %c\n", &r, &c, &p);
	for (i = 1; i <= r; i++)
		for (j = 1; j <= c; j++)
			scanf (" %c", &m[i][j]);
	for (i = 1; i <= r; i++)
		for (j = 1; j <= c; j++)
			if (m[i][j] == p)
				C[m[i][j-1]] = C[m[i][j+1]] =
				C[m[i-1][j]] = C[m[i+1][j]] = 1;
	for (i = 'A'; i <= 'Z'; i++)
		ans += C[i];
	printf("%d", ans - C[p]);
	return 0;
}

