// zadacha 'prosto'
// LKSH A(2009) - 1day
// formula +/-
// skol'ko chisel v [A,B], kotorye ne
// delyatsya na p[i] (0..n)
#include <cstdio>

const int maxn = 20;
int n, i, j, p[maxn], f, A, B, ans, q;
int main ()
{
	scanf ("%d", &n);
	for (i = 0; i < n; i++)
		scanf ("%d", &p[i]);
	scanf ("%d%d", &A, &B);
	
	for (i = 0; i < (1 << n); i++)
	{
		q = 1;
		f = 1;
		for (j = 0; j < n; j++)
			if (i & (1 << j))
			{
				f = -f;
				q *= p[j];
			}
		ans += f * (B / q - (A - 1) / q);
		// skol'ko chisel v [0,B] - [0,A-1]
		// chisel v [0, I] = I / q
		// gde q = LCM(p[i]) dlya vseh ispol'z. i v maske
		// if maska%2==0, togda +, else -
	}

	printf("%d", ans);

	return 0;
}

