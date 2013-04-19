#include <cstdio>
#include <algorithm>

using namespace std;

struct pt	{	int x, y;	};
int operator * (pt a, pt b)
{	return a.x * b.y - b.x * a.y;	}

pt operator - (pt a, pt b)
{
	pt r = a;
	r.x -= b.x;
	r.y -= b.y;
	return r;
}

bool operator == (pt a, pt b)	{	return a.x == b.x && a.y == b.y;	}

bool cmp (pt a, pt b)
{
	return (a * b > 0 || (a * b == 0 && a.x*a.x + a.y*a.y < b.x*b.x + b.y*b.y));
}
struct ang	{	int a, b;	};
bool operator < (const ang & p, const ang & q)
{
	if (p.b == 0 && q.b == 0)
		return p.a < q.a;
	return p.a * 1ll * q.b < p.b * 1ll * q.a;
}

long long sq (pt &a, pt &b, pt &c)
{
	return a.x * 1ll * (b.y - c.y) + b.x*1ll*(c.y-a.y) + c.x*1ll*(a.y-b.y);
}

ang p[500000];


int n, zero, st[500000], k;
pt a[500000], M, N ,con[500000];
int main ()
{
	freopen ("C.in", "r", stdin);
	freopen ("C.out", "w", stdout);
	scanf ("%d", &n);
	for (int i = 0; i < n; i++)
		scanf ("%d%d", &a[i].x, &a[i].y);
	for (int i = 1; i < n; i++)
		if (a[zero].y > a[i].y || (a[zero].y == a[i].y && a[zero].x > a[i].x))
			zero = i;
	M = a[zero];
	swap (a[zero], a[0]);
	for (int i = 0; i < n; i++)
		a[i] = a[i] - M;
	sort (a + 1, a + n, cmp);
	st[0] = 0;
	for (int i = 1; i < n;)
		if ( !k || (a[st[k]] - a[st[k - 1]]) * (a[i] - a[st[k - 1]]) > 0)
			st[++k] = i++;
		else k--;
	k++;
	for (int i = 0; i < k; i++)
		con[i] = a[st[i]];
	sort(con, con + k, cmp);
	for (int i = 0; i < k; i++)
		con[i].x += M.x, con[i].y += M.y;
	for (int i = 0; i < k - 1; i++)
	{
		p[i].a = con[i + 1].y - M.y;
		p[i].b = con[i + 1].x - M.x;
		if (p[i].a == 0)
			p[i].b = p[i].b < 0 ? -1 : 1;
	}n--;
	int m, ans = 0;
	pt q;
	scanf ("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf ("%d%d", &q.x, &q.y);
		bool in = 0;
		if (q.x >= M.x){
			if (q.x == M.x && q.y == M.y)
				in = true;
			else
			{
				ang my = {q.y - M.y, q.x - M.x};
				if (!my.a)
					my.b = my.b < 0 ? -1 : 1;
				int it = upper_bound(p, p + n, my) - p;
				if (it == n && my.a == p[n - 1].a && my.b == p[n - 1].b)
					it = n - 1;
				if (it != n && it != 0)
					if (sq(con[it], con[it - 1], q) <= 0)
						in = true;
			}
//			fprintf(stderr, "upper than zero");
		}
		ans += in ? 1 : -1;
	}

	printf("%d\n", ans);
	return 0;
}



