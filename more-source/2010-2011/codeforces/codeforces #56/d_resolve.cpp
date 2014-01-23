// Kim Vyacheslav
// 2011
#include <cstdio>
#include <algorithm>

using namespace std;

#define N 10000010
int n, a[N], p[N], ans;
long long x, y, z, i, j;

int Find(int x) {return x == p[x] ? x : p[x] = Find(p[x]);}
int Union (int x, int y)
{
    if (p[x] && p[y] && Find(x) != Find(y)){
        if (rand() & 1)
            swap(x, y);
        p[Find(x)] = Find(y);
        return 1;
    }
    return 0;
}

int main ()
{
    scanf ("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf ("%d", &x);
        p[x] = x;
    }

    for (i = 1; i < N; i++)
        for (j = i + 1; (x = j * j - i * i) < N && (y = 2 * j * i) < N; j++)
            if (1&(i + j) && __gcd(i, j) == 1)
            {
                z = j * j + i * i;
                ans += Union(x, y);
                if (z < N)
                    ans += Union(x, z) +
                           Union(y, z);
            }
    printf("%d", n - ans);
    return 0;
}

