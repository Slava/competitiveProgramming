#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <cstdio>

using namespace std;

struct pt
{
    int x, y;
    void operator = (const pt &a)
    {
        x = a.x;
        y = a.y;
    }
    int dis (const pt &a)
    {
        return ((x-a.x)*(x-a.x) + (y-a.y)*(y-a.y));
    }
    pt operator - (const pt &a) const
    {
        pt r;
        r.x = x-a.x;
        r.y = y-a.y;
        return r;
    }
    int operator * (const pt &a) const
    {
        return (x*a.y - a.x*y);
    }
}a[2010];

int x;


int VM (pt a, pt b)
{
    return (a.x*b.y - b.x*a.y);
}


bool cmp (pt a, pt b)
{
    return (VM (a, b) > 0 || (VM(a, b) == 0 && a.x*a.x+a.y*a.y < b.x*b.x+b.y*b.y));
}

vector<int> convex_h ( int n)
{
	pt m;
	x = -1;

	int r[21000], i;

	for (i = 0; i < n; i++)
	{
		if((x == -1 || a[x].y > a[i].y) || (a[x].y == a[i].y && a[x].x > a[i].x))  x = i;
	}
	m = a[x];
	swap (a[x], a[0]);
	for (i = 0; i < n; i++)	a[i].x -= m.x, a[i].y -= m.y;
	sort (a+1, a+n, &cmp);
	r[0] = 0;
	int k = 0;

	for (i = 1; i < n;)
	{
		if ( k == 0 || ((a[r[k]]-a[r[k-1]])*(a[i]-a[r[k]])) > 0 )
		{
			r[++k] = i;
			++i;
		}
		else
		{
			k--;
		}
	}
	vector <int> res;
	for (i = 0; i <= k; i++)res.push_back(r[i]);
	return res;
}

int main ()
{

    int n, i, k;
    scanf("%d", &n);

    vector <int> q;

    for (i = 0; i < n; i++) scanf ("%d%d", &a[i].x, &a[i].y);

        q = convex_h (n);
        k = q.size();
		printf("%d\n", k);
		for (int i = 0; i < k; i++)
			printf("%d %d\n", a[q[i]].x, a[q[i]].y);


    return 0;
}
