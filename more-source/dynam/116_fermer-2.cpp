#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 10099;
int n, m, a[maxn][maxn],
    l[maxn], r[maxn],
    h[maxn], stack[maxn],
    i, j, ans;
char c[maxn];

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    scanf ("%d%d", &n, &m);
    for (i = 1; i <= n; i++)
    {
        scanf ("%s", c);
        for (j = 1; j <= m; j++)
            a[i][j] = c[j - 1] - 48;
    }
    for (i = 1; i <= n; i++)
    {
        memset(l, 0, sizeof(l));
        memset(r, 0, sizeof(r));

        for (j = 1; j <= m; j++)
            h[j] = a[i][j] ? h[j] + 1 : 0;

        for (j = 1; j <= m; j++)
        {
            while (h[stack[stack[0]]] > h[j])
                r[stack[stack[0]--]] = j - 1;
            stack[++stack[0]] = j;
        }
        for (; stack[0]; stack[0]--)
            r[stack[stack[0]]] = m;
        for (j = m; j; j--)
        {
            while (h[stack[stack[0]]] > h[j])
                l[stack[stack[0]--]] = j + 1;
            stack[++stack[0]] = j;
        }
        for (; stack[0]; stack[0]--)
            l[stack[stack[0]]] = 1;
        for (j = 1; j <= m; j++)
            if (ans < h[j] * (r[j] - l[j] + 1))
                ans = h[j] * (r[j] - l[j] + 1);
    }

    printf ("%d", ans);

    return 0;
}

