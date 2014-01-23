// Kim Vyacheslav KarKTL
//vtoroe Ost derevo Kruskal
#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 100
#define maxm 1000
#define inf 1000*1000

#define debug

int m, n,
    p[maxn], r[maxn];
bool u[maxm], mst[maxm];  //used and mst edges

pair<int, pair<int,int> >a[maxn];

int findset (int x)
{
    if (p[x] != x)
        p[x] = findset(p[x]);
    return p[x];
}

void unionset (int x, int y)
{
    x = findset(x);
    y = findset(y);
    if (r[x] > r[y])
        p[y] = x;
    else
    {
        p[x] = y;
        if (r[x] == r[y])
            r[y]++;
    }
}

int kruskal (bool first)
{
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        if (u[i])
            continue;
        if (findset(a[i].second.first) != findset(a[i].second.second))
        {
            unionset(a[i].second.first, a[i].second.second);
            if (first) mst[i] = 1;
            sum += a[i].first;
        }
    }

    if (!sum) inf;
    return sum;
}

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    scanf ("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
        p[i] = i;
    for (int i = 0; i < n; i++)
        r[i] = 0;

    for (int i = 0; i < m; i++)
    {
        int q, w, e;
        scanf ("%d %d %d", &q, &w, &e);
        a[i] = make_pair(e, make_pair(w-1,q-1));
    }

    sort (a, a+m);
    kruskal(1);
    int M = inf;
    for (int i = 0; i < m; i++)
    {
        if (mst[i])
        {
            for (int i = 0; i < n; i++)
                p[i] = i;
            for (int i = 0; i < n; i++)
                r[i] = 0;
            u[i] = 1;;
            M = min (M, kruskal(0));
            u[i] = 0;
        }
    }

    printf ("%d", M);

    return 0;
}
