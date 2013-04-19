// 231
#include <cstdio>

bool p[1010101];
int n, a[9000], an;
int main ()
{
	scanf ("%d", &n);
	for (int i = 2; i <= n; i++)if (!p[i]){
		for (int j = i + i; j <= n; j += i)
			p[j] = 1;
		if (i - 2 > 1 && !p[i - 2])
			a[an++] = i - 2;
	}
	printf("%d\n", an);
	for (int i = 0; i < an; i++)
		printf("2 %d\n", a[i]);
	return 0;
}

