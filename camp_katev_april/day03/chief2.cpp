#include <cstdio>
#include <algorithm>

using namespace std;

#define a second.first
#define b first
#define c second.second

pair<int, pair<int, int> >d[5100];
int n, r[5100], t[5100], ans, bns;
int main ()
{
	freopen ("chief2.in", "r", stdin);
	freopen ("chief2.out", "w", stdout);
	
	scanf ("%d", &n);
	for (int i = 0; i < n; i++)
		scanf ("%d%d%d", &d[i].a, &d[i].b, &d[i].c);
	sort(d, d + n);
	for (int i = 0; i < n; i++)
	{
		int p, s; p = s = 0;
		r[i] = d[i].c; 
		t[i] = d[i].b - d[i].a ;
		for (int j = i - 1; j >= 0; j--)
			if (d[j].b < d[i].a && (r[j] > p || (r[j] == p && s > t[j])))
				p = r[j], s = t[j];
		r[i] += p;
		t[i] += s;
		if (ans < r[i] || (ans == r[i] && bns > t[i]))
			ans = r[i], bns = t[i];
	}
	printf ("%d %d", ans, bns);
	return 0;
}

