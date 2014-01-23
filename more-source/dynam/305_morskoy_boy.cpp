// Kim Vyacheslav
// Karaganda KTL 2010
// (*this) == fermer-2;
#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#define pb push_back
#define dbg(x) cout<<#x<<"="<<x<<" "
using namespace std;

const int maxn = 1099;
int n, m, k, a[maxn][maxn],
    l[maxn], r[maxn],
    h[maxn], stack[maxn],
    i, j, ans, x1, x2, y1, y2;
vector<int> x_1, x_2, y_1, y_2;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    scanf ("%d%d%d", &n, &m, &k);
    for (i = 1; i <= k; i++)
        for (scanf ("%d%d%d%d", &y1, &x1, &y2, &x2); y1 <= y2; y1++)
            for (j = x1; j <= x2; j++)
                a[y1][j] = 1;

    for (i = 1; i <= n; i++)
    {
        memset(l, 0, sizeof(l));
        memset(r, 0, sizeof(r));

        for (j = 1; j <= m; j++)
            h[j] = a[i][j] ? 0 : h[j] + 1;

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
            {
//                x_1.clear(); x_2.clear(); y_1.clear(); y_2.clear();
                x_1.pb(l[j]); y_1.pb(i - h[j] + 1);
                x_2.pb(r[j]); y_2.pb(i);
                ans = h[j] * (r[j] - l[j] + 1);
            }
            else if (ans == h[j] * (r[j] - l[j] + 1))
            {
                x_1.pb(l[j]); y_1.pb(i - h[j] + 1);
                x_2.pb(r[j]); y_2.pb(i);
            }
    }

    ans = 0;
    for (int k = 0; k < x_1.size(); k++)
    {
        if (a[y_1[k] - 1][x_1[k] - 1])
            x_1[k]++, y_1[k]++;
        if (a[y_2[k] + 1][x_1[k] - 1])
            x_1[k]++, y_2[k]--;
        if (a[y_1[k] - 1][x_2[k] + 1])
            x_2[k]--, y_1[k]++;
        if (a[y_2[k] + 1][x_2[k] + 1])
            x_2[k]--, y_2[k]--;
        for (i = x_1[k]; i <= x_2[k]; i++)
        {
            if (a[y_2[k] + 1][i])
                y_2[k]--;
            if (a[y_1[k] - 1][i])
                y_1[k]++;
        }
        for (i = y_1[k]; i <= y_2[k]; i++)
        {
            if(a[i][x_1[k] - 1])
                x_1[k]++;
            if(a[i][x_2[k] + 1])
                x_2[k]--;
        }

        ans = max((y_2[k] - y_1[k] + 1) * (x_2[k] - x_1[k] + 1), ans);
    }

    printf ("%d", ans);

    return 0;
}

