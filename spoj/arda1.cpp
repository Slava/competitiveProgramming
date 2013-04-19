#include <cstdio>

typedef unsigned long long ull;
const int N = 310;
const int M = 2010;
int n1, m1, n2, m2;
char s[N][N], m[M][M];
ull h[N], h2[M][N], p_pow[M];

int main ()
{
	p_pow[0] = 1;
	for (int i = 0; i < M; i++)
		p_pow[i] = 31 * p_pow[i - 1];
	scanf ("%d %d\n", &n1, &m1);
	for (int i = 0; i < n1; i++)
		scanf ("%s\n", s[i]);
	for (int i = 0; i < n1; i++)
		for (int j = 0; j < m1; j++)
		{
			h[i] *= 31;
			h[i] += s[i][j] - 'a' + 1;
		}
	scanf ("%d %d\n", &n2, &m2);
	for (int i = 0; i < n2; i++)
		scanf ("%s\n", m[i]);
	for (int i = 0; i < n2; i++)
	{
		for (int j = 0; j < m2; j++)
		{
			if (j)
				h2[i][j] += h2[i][j - 1];
			h2[i][j] *= 31; h2[i][j] += m[i][j] - 'a' + 1;
		}
		for (int j = m1 - 1, k = 0; j < m2; j++, k++)
		{
			ull hash = 
		}
	}
	
	return 0;
}

