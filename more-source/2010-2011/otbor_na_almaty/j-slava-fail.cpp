#include <cstdio>
#include <cmath>

using namespace std;

#define maxh 100000000

long t[maxh], N, n, k, v, h, a[maxh], T;
int sum (int r)
{
	int result = 0;
	for (; r >= 0; r = (r & (r+1)) - 1)
		result += t[r];
	return result;
}

void inc (int i, int delta)
{
	for (; i < n; i = (i | (i+1)))
		t[i] += delta;
}

int sum (int l, int r)
{
	return sum (r) - sum (l-1);
}


long prevtime;
double S;
int main ()
{
    freopen ("water.in","r",stdin);
    //freopen ("water.out","w",stdout);

    scanf ("%ld%ld", &N, &n);
    S = n;
    for (int i =0; i < N; i++)
    {
        scanf ("%ld", &k);

        switch (k)
        {
            case 1:
            scanf ("%ld%ld%ld", &T, &h, &v);
            a[h] += v;
            inc(h, v);
            for (int j = 0; j <= n; j++)
            {
                printf ("%ld ", a[j]);
            }printf ("\n");
            S -= (T-prevtime) * (sum(0,S));
            prevtime = T;
            break;

            case 2:
            scanf ("%ld%ld", &T, &h);
            S -= (T-prevtime) * (sum(0,S));
            inc (h,-a[h]);
            a[h] = 0;
            prevtime = T;
            break;

            case 3:
            scanf ("%ld", &T);
            S -= (T-prevtime) * (sum(0,floor(S)-1));
            prevtime = T;
            if (S < 0)S = 0;
            printf ("%.9lf\n", S);
            break;
        }
            if (S < 0)S = 0;
        printf ("S=%lf prevt=%ld t=%ld sum=%ld\n",S,prevtime,T,sum(0,S));

    }

    return 0;
}

