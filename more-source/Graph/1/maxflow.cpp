#include <cstdio>
#include <iostream>

using namespace std;

#define MAXN 1000
#define inf 1000*1000
#define min(a,b) (a<b?a:b)

int c[MAXN][MAXN],
    f[MAXN][MAXN],
    n, i, j,
    from[MAXN],
    q[MAXN*MAXN],
    h, t, source, sink;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    cin >> n >> source >> sink;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            cin >> c[i][j];
// c[j][i] != -c[i][j] (!!!!!!)


    for (;;)
    {
        h = t = 0;
        for (i = 0; i < n; i++)
            from[i] = -1;
        //bfs, nahojdenije uluchshayuschego putya
        from[source] = source;
        q[t++] = source;
        for (int cur; h < t; h++)
        {
            cur = q[h];
            for (int v = 0; v < n; v++)
            {
                if (from[v] == -1 && (c[cur][v]-f[cur][v]) > 0)
                {
                    q[t++] = v;
                    from[v] = cur;
                }
            }
        }

        if (from[sink] == -1)   //net novogo puti
            break;
        int cf = inf;

        for (int cur = sink; cur != source;)
        {
            int prev = from[cur];
            cf = min (cf, c[prev][cur] - f[prev][cur]);
            cur = prev;
        }
        //conservation flow
        //sohraneniya potoka
        for (int cur = sink; cur != source;)
        {
            int prev = from[cur];
            f[prev][cur] += cf;
            f[cur][prev] -= cf;     //f(u,v) = -f(v,u) (!!!!!!!!)
            cur = prev;
        }
    }

    int flow = 0;
    for (i = 0; i < n; i++)
        if (c[source][i])
            flow += f[source][i];

    printf ("%d", flow);

    return 0;
}
