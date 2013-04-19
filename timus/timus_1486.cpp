#include <cstdio>
#include <cstdlib>
#define min(a,b) (a<b?a:b)

const int N = 600;
typedef unsigned long long ull;
ull pr[N + 9][N + 9], ppow[N + 9], qpow[N + 9],
	P = 105253, Q = 1299989;
int n, m, a1x, a1y, a2x, a2y, usedn, used[1000009],
	mid, l, r;
struct node{
	ull x; int i, j, ne;
} Nodes[N * N + 9];
int mm, hashtable[1000007];
int New (ull _, int __, int ___)
{
	++mm;
	Nodes[mm].x = _;
	Nodes[mm].j = __;
	Nodes[mm].i = ___;
	Nodes[mm].ne = 0;
	return mm;
}

void add (ull h, int x, int y)
{
	ull p = h % 1000007;
	if (!hashtable[p])
	{
		hashtable[p] = New(h, x, y);
		used[usedn++] = (int)p;
	}
	else
	{
		int n = New(h, x, y);
		Nodes[n].ne = hashtable[p];
		hashtable[p] = n;
	}
}

bool search (ull h)
{
	unsigned int p = h % 1000007, o;
	o = hashtable[p];
	for (; o; o = Nodes[o].ne)
		if (Nodes[o].x == h)
		{
			a1x = Nodes[o].i;
			a1y = Nodes[o].j;
			return 1;
		}
	return 0;
}

inline ull myhash (int x1, int x2, int y1, int y2)
{
	ull h = pr[y2][x2];
	if (x1) h -= pr[y2][x1 - 1];
	if (y1) h -= pr[y1 - 1][x2];
	if (y1 && x1) h += pr[y1 - 1][x1 - 1];
	h *= ppow[n - 1 - y2] * qpow[m - 1 - x2];
	return h;
}

bool can (int k)
{
	bool flag = 0;
	for (int i = 0; i + k <= n && !flag; i++)
		for (int j = 0; j + k <= m; j++)
		{
			ull h = myhash(j, j + k - 1, i, i + k - 1);
			if (search(h))
			{
				a2x = i; a2y = j;
				flag = true;
				break;
			}
			add(h, j, i);
	}
	for (int i = 0; i < usedn; i++)
		hashtable[used[i]] = 0;
	mm = usedn = 0;
	return flag;
}

int main ()
{
	scanf ("%d%d\n", &n, &m);
	ppow[0] = qpow[0] = 1;
	for (int i = 1; i < n; i++)
		ppow[i] = ppow[i - 1] * P;
	for (int j = 1; j < m; j++)
		qpow[j] = qpow[j - 1] * Q;
	char ch;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%c", &ch);
			pr[i][j] = (ch - 'a' + 1) * ppow[i] * qpow[j];
			if (i)	pr[i][j] += pr[i - 1][j];
			if (j)	pr[i][j] += pr[i][j - 1];
			if (i && j)	pr[i][j] -= pr[i - 1][j - 1];
		}
		scanf("\n");
	}
	l = 1, r = min(m, n);
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (can(mid))
			l = mid + 1;
		else r = mid - 1;
	}
	if (l > 1){
		printf("%d\n", l - 1);
		printf("%d %d\n%d %d\n", a1x + 1, a1y + 1, a2x + 1, a2y + 1);
	}
	else puts("0");
	return 0;
}

