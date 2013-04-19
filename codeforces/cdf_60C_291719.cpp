// Kim Vyacheslav
// 2011
#include <cstdio>
#include <vector>

using namespace std;

#define pb push_back
#define ll long long

const int inf = 1e6;
const int NN = 110;

vector<int> g[NN];
long long n, m, ans[NN], u[NN],
    nd[NN][NN], nk[NN][NN];

long long gcd (long long a, long long b)
{
    while (a && b)
        a > b ? a %= b : b %= a;
    return a + b;
}

long long lcm (long long a, long long b)
{
    ll t = a * b;
    t /= gcd(a, b) * 1ll;
    return t;
}

bool zero()
{
    for (int i = 0; i < n; i++)
        u[i] = 0;
    return 1;
}

bool check (long long v, long long av)
{
    u[v] = 1;
    ans[v] = av;
    for (int i = 0; i < g[v].size(); i++)
    {
        long long to = g[v][i];
        ll t = (nk[v][to]) * (nd[v][to]);
        if (t % (av) != 0)
            return 0;
        t /= av;
        if (!u[to])
            if(!check(to, t))
                return 0;
        if (gcd(av, ans[to]) == nd[v][to] &&
            lcm(av, ans[to]) == nk[v][to]);
        else return 0;
    }
    return 1;
}

bool solve (long long v)
{
    long long j = 1;
    for (; j <= inf; j++)
        if (zero() && check(v, j))
            break;
    return j <= inf;
}
int main ()
{
    scanf ("%I64d%I64d", &n, &m);
    while (m--)
    {
        long long x, y, nod, nok;
        scanf ("%I64d%I64d%I64d%I64d", &x, &y, &nod, &nok);
        x--, y--;
        nd[y][x] = nd[x][y] = nod;
        nk[y][x] = nk[x][y] = nok;
        g[x].pb(y); g[y].pb(x);
    }
    for (int i = 0; i < n; i++)
        if (!ans[i] && !solve(i))
        {
            puts("NO");
            return 0;
        }
    puts("YES");
    for (int i = 0; i < n; i++)
        printf("%I64d ", ans[i]);
    return 0;
}





// lang: GNU C++
// memory: 1600 KB
// author: imslavko
// submit_date: Feb 19, 2011 11:21:26 PM
// contest: 60
// link: /contest/60/submission/291719
// time: 140 ms
// verdict: Accepted
// problem: 60C - Mushroom Strife
// ID: 291719
// downloaded by very stupid script
