#include <cstdio>
#include <algorithm>

using namespace std;

struct pt	{	double x, y;	};
double area (pt a, pt b, pt c){	return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);	}
bool inInterval (double a, double b, double c, double d)
{	return max(a,b) >= min(c,d) && min(a,b) <= max(c,d);	}
bool intersect (pt a, pt b, pt c, pt d)
{
	double aa = area(a, b, c),
		   ab = area(a, b, d),
		   ba = area(c, d, a),
		   bb = area(c, d, b);
	if (!aa && !ab && !ba && !bb)
		return inInterval(a.x, b.x, c.x, d.x) && inInterval(a.y, b.y, c.y, d.y);
	return (aa * ab <= 0) && (ba * bb <= 0);
}

bool in (double a, double b, double c)	{return a <= c && c <= b;}

pt a[300], b[300];
bool recint (int x, int y)
{
	double x1 = a[x].x, x2 = b[x].x, y1 = a[x].y, y2 = b[x].y;
	double x3 = a[y].x, x4 = b[y].x, y3 = a[y].y, y4 = b[y].y;
	if (x1 > x2)swap(x1,x2);
	if (x3 > x4)swap(x3,x4);
	if (y3 > y4)swap(y3,y4);
	if (y1 > y2)swap(y1,y2);
	if (
		(in(x1, x2, x3) && in(x1,x2,x4) && in(y1,y2,y3) && in(y1,y2,y4)) || 
		(in(x3, x4, x1) && in(x3,x4,x2) && in(y3,y4,y1) && in(y3,y4,y2))
	)
		return 1;
	pt A[4], B[4], C[4], D[4];
	A[0].x = A[1].x = x1,
	A[2].x = A[3].x = x2;
	A[0].y = A[1].y = y2,
	A[2].y = A[3].y = y1;
	B[0].x = B[2].x = x1,
	B[1].x = B[3].x = x2;
	B[0].y = B[2].y = y1;
	B[1].y = B[3].y = y2;
	C[0].x = C[1].x = x3,
	C[2].x = C[3].x = x3;
	C[0].y = C[1].y = y4,
	C[2].y = C[3].y = y3;
	D[0].x = D[2].x = x3,
	D[1].x = D[3].x = x4;
	D[0].y = D[2].y = y3;
	D[1].y = D[3].y = y4;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (intersect(A[i], B[i], C[j], D[j]))
				return 1;
	return 0;
}

int p[300], ex[300];

int find (int x)
{
	if (p[x] != x)
		p[x] = find(p[x]);
	return p[x];
}

void Union (int x, int y)
{
	x = find(x);
	y = find(y);
	if (rand() & 1)
		p[x] = y;
	else p[y] = x;
}

int n, ans;
int main ()
{
	freopen ("newarea.in", "r", stdin);
	freopen ("newarea.out", "w", stdout);
	scanf ("%d", &n);
	for (int i = 0; i < n; i++)
		p[i] = i;
	for (int i = 0; i < n; i++)
		scanf ("%lf%lf%lf%lf", &a[i].x, &a[i].y, &b[i].x, &b[i].y);
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (find(i) != find(j) && recint(i, j))
				Union(i, j);
	for (int i = 0; i < n; i++)
		p[i] = find(i),	ex[p[i]]++;
	for (int i = 0; i < n; i++)
		ans = max(ans, ex[i]);
	printf("%d", ans);
	return 0;
}

