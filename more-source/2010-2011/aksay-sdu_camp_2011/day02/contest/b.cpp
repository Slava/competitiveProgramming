#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long max (long a, long b)
{
    if (a > b)
        return a;
    return b;
}

bool u[3001];
long n, from, to, ans, ans2;
vector <long> a[3001], pathes;

int dfs (long v)
{
    vector<long>d;
    u[v] = true;
    long maxlen = 0;
    for (int i = 0; i < a[v].size(); i++)
    {
        long to = a[v][i];
        if (!u[to])
            d.push_back( dfs(to) + 1 );
    }

    sort (d.begin(), d.end());
    if (d.size()) maxlen = d[d.size() - 1];
    if (d.size() > 1)
    {
        if(ans < maxlen + d[d.size() - 2])
            ans = maxlen + d[d.size() - 2];
    }
    return maxlen;
}

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    scanf ("%ld", &n);
    for (int i = 1; i < n; i++)
    {
        scanf ("%ld%ld", &from, &to);
        a[from].push_back(to);
        a[to].push_back(from);
    }

    for (int i = 1; i <= n; i++)
        if (!u[i])
            pathes.push_back(dfs(i));

    sort (pathes.begin(), pathes.end());

    ans2 = pathes.back();
    if (pathes.size() > 1)
        ans2 += pathes[pathes.size() - 2];

    printf ("%ld", max(ans2 + 1, ans));

    return 0;
}

