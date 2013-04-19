// 181
#include <cstdio>
#define h "%d"

int a, b, c, x[1011], m, n, r, cycle, N;
int main ()
{
	scanf (h h h h h h , &r, &a, &b, &c, &m, &n);
	for (; !cycle && n; n--)
	{
		r = (r * 1ll * r * 1ll * a * 1ll + r * 1ll * b * 1ll + c * 1ll) % m;
		x[N++] = r;
		for (int j = 0; j < N - 1; j++)
			if (x[j] == r)
			{
				cycle = 1;
				N -= j + 1;
			}
	}
	n %= N;
	for (; n; n--)
		r = (r * 1ll * r * 1ll * a * 1ll + r * 1ll * b * 1ll + c * 1ll) % m;
	printf(h, r);
	return 0;
}
