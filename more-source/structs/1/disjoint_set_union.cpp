#include <cstdio>
using namespace std;
#define maxn 1000
int p[maxn], r[maxn];

int findset(int x)
{
    if (p[x] == x)
        return x;
    return x = findset(p[x]);
}

void unionset (int u, int v)
{
    u = findset (u);
    v = findset (v);
    if (r[u] >= r[v])
        if (r[u] == r[v])
        {
            p[u] = v;
            r[u]++;
        }
        else p[v] = u;
    else p[u] = v;
}

int main ()
{
    int n;
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        p[i] = i;

    return 0;
}

