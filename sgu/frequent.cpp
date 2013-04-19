#include <cstdio>
#include <algorithm>

const int N = 101010;
int a[N], b[N], n, q, A, B;
struct node 
{
	int l, r, m;
	void s(int x) {l = r = m = x;}
}t[N*4];


void build (int i = 1, int l = 0, int r = n - 1)
{
	if (l == r)
		t[i].s( !a[l] );
	else
	{
		int m = (l + r) / 2;
		build(i + i, l, m);
		build(i + i + 1, m + 1, r);
		
	}
}

int sum (int l, int r, int i = 1, int tl = 0, int tr = n - 1)
{
	if (l == tl && r == tr)
		return t[i];
	int m = (tl + tr) / 2;
	if (l > m)
		return sum(l, r, i + i + 1, m + 1, tr);
	if (r <= m)
		return sum(l, r, i + i, tl, m);
	return sum(l, m, i + i, tl, m) + sum(m + 1, r, i + i + 1, m + 1, tr);
}

void solve ()
{
	scanf ("%d", &q);
	for (int i = 0; i < n; i++)
		scanf ("%d", b + i);
	for (int i = 1; i < n; i++)
		a[i] = b[i] - b[i - 1];
	a[0] = 1;
	puts("a = ");for (int i = 0; i < n; i++)printf("%d ", a[i]);puts(" print finished");
	build();
	puts("tree : ");for (int i = 1; i < n * 2; i++)printf("%d ", t[i]);puts(" tree finished");
	while (q--)
	{
		scanf ("%d%d", &A, &B);
		printf("%d\n", sum(A, B - 1) + 1);
	}
	for (int i = 0; i < 4 * n; i++)t[i] = 0;
}
int main ()
{
	while (scanf ("%d", &n) == 1)
		if (n)
			solve();
	return 0;
}

