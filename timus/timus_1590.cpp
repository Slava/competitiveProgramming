#include <cstdio>
#include <cstring>

typedef unsigned int ull;
const int N = 5010;
const int hts = 10000007;
struct No{
	ull x; No *ne;
}nodes[12502510];
int mm, usd[12502510], usdn;
No *he[hts];
No *New(ull _)
{
	nodes[mm].x = _;
	nodes[mm].ne = NULL;
	return &nodes[mm++];
}

bool find_hash (ull x, ull y)
{
	ull p = x % hts;
	No *c = he[p];
	for (; c; c = c->ne)
		if (y == c->x)
			return true;
		else if (y < c->x)
			break;
	return false;
}

void add_hash (ull x, ull y)
{
	ull p = x % hts;
	No *u = New(y);
	if (!he[p] || y < he[p]->x)
	{
		u->ne = he[p];
		he[p] = u;
		usd[usdn++] = p;
	}
	else for (No *c = he[p]; c; c = c->ne)
			if(!c->ne || c->ne->x > y)
			{
				u->ne = c->ne;
				c->ne = u;
				return;
			}
}

char s[N];
ull pr[N], p[N], q[N], qr[N], 
	P = 3571, Q = 111191111;
int n, ans;

void hash (int l, int r, ull &x, ull &y)
{
	x = pr[r]; y = qr[r];
	if (l) x -= pr[l - 1], y -= qr[l - 1];
	x *= p[n - l - 1]; y *= q[n - l - 1];
}

void check (int l)
{
	ull h, h2;
	for (int i = 0; i + l < n; i++){
		hash(i, i + l, h, h2);
		if (!find_hash(h, h2))
			add_hash(h, h2), ans++;
	}
	for (int i = 0; i < usdn; i++)
		he[usd[i]] = NULL;
	mm = usdn = 0;
}

int main ()
{
	scanf("%s", s);
	n = strlen(s);
	p[n - 1] = q[n - 1] = 1;
	for (int i = n - 2; i >= 0; i--)
		p[i] = p[i + 1] * P,
		q[i] = q[i + 1] * Q;
	for (int i = 0; i < n; i++)
	{
		pr[i] = (s[i] - 'a' + 1) * p[i];
		qr[i] = (s[i] - 'a' + 1) * q[i];
		if (i) pr[i] += pr[i - 1],
			qr[i] += qr[i - 1];
	}
	
	for (int i = 0; i < n; i++)
		check(i);
	printf("%d\n", ans);
	return 0;
}

