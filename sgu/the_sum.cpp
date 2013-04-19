#include <cstdio>

int f[50] = {0, 1}, k;
long long s;
int main ()
{
	scanf ("%d", &k);
	for (int i = 2; i <= k; i++)
		f[i] = f[i - 1] + f[i - 2];
	for (int i = 0; i <= k; i++)
		s += f[i];
	printf("%lld", s);
	return 0;
}

