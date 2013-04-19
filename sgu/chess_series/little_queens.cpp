#include <cstdio>

bool r[12], c[12], d[22], w[22];
int n, k;

bool D(int x, int y)
{
	return r[x] | c[y] | d[x + y] | w[x + n - y - 1];
}

void mark (int x, int y, int p = 1)
{
	r[x] = c[y] = d[x + y] = w[x + n - y - 1] = p;
}

long long f (int x, int l)
{
	if (!l)
		return 1;
	if (x == n)
		return 0;
	long long r = 0;
	for (int y = 0; y < n; y++)
		if (!D(x, y))
		{
			mark(x, y);
			r += f (x + 1, l - 1);
			mark(x, y, 0);
		}
	r += f(x + 1, l);
	return r;
}

int main ()
{
	scanf ("%d%d", &n, &k);
	long long s = f(0, k);
	printf("%lld", s);
	return 0;
}

