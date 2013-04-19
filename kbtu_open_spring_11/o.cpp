#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

char c;
int a[1009][1009], n, m, i, j, k, l, x[1000009], y[1000009], x1, y1, h[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
main ()
{
    freopen ("war.in", "r", stdin);
    freopen ("war.out", "w", stdout);
    cin >> m >> n;
    for(i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            cin >> c;
            a[i][j] = (c == '1' ? 1 : 0);
        }
    }
    cin >> x1 >> y1;
    x[l] = x1;
    y[l] = y1;
    l++;
    for (i = 0; i < l; i++)
    {
        for (j = 0; j < 4; j++)
        {
            int dx = h[j][0] + x[i], dy = h[j][1] + y[i];
            if (dx >= 1 && dx <= m && dy >= 1 && dy <= n && a[dy][dx] == 0)
            {
                a[dy][dx] = 1;
                x[l] = dx;
                y[l] = dy;
                l++;
            }
        }
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
            cout << a[i][j];
        cout << endl;
    }
}
