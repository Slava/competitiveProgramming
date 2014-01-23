#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;


vector<long> t;
vector<long> a;
long n;

void qinit (long nn)
{
	n = nn;
	t.assign (n, 0);
}

long sum (long r)
{
	long result = 0;
	for (; r >= 0; r = (r & (r+1)) - 1)
		result += t[r];
	return result;
}

void inc (long i, long delta)
{
	for (; i < n; i = (i | (i+1)))
		t[i] = t[i] + delta;
}

long qsum (long l, long r)
{
	return sum (r) - sum (l-1);
}

void init (vector<long> a)
{
	qinit ((long) a.size());
	for (long i = 0; i < a.size(); i++)
		inc (i, a[i]);
}

 main ()
{
    freopen ("enigmatic.in", "r", stdin);
    freopen ("enigmatic.out", "w", stdout);

    long n, t, m, l, r;
    scanf ("%ld", &n);
    for (long i = 0; i < n; i++)
    {
        scanf ("%ld", &t);
        a.push_back(t);
    }
    init(a);
    scanf ("%ld", &m);
    for (long i = 0; i < m; i++)
    {
        scanf ("%ld%ld%ld",&t,&l,&r);
        if (t == 1)
        {
            for (long j = l; j <= r; j++){
                inc(j-1,((a[j-1]*a[j-1])%2010)-a[j-1]);
                a[j-1]*=a[j-1];
            }
        }
        else
            printf ("%ld\n", qsum(l-1,r-1));
    }

    return 0;
}
