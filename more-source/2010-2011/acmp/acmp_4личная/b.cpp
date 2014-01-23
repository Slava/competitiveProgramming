#include <cstdio>
#include <iostream>

using namespace std;


char c;
int n, m, a[1009][1009], maxi, maxj, mini, minj;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    maxi = maxj = 0;
    mini = minj = 1008;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> c;
            if (c == '*')
            {
                a[i][j] = 1;
                mini = min (mini, i);
                minj = min (minj, j);
                maxj = max (maxj, j);
                maxi = max (maxi, i);
            }
        }
    bool T = 1;

    for (int i = mini + 2; i <= maxi - 2; i++ )
        for (int j = minj + 2; j <= maxj - 2; j++)
            if(!a[i][j])T = 0;

    if (T) puts("SQUARE");
    else puts("CIRCLE");

    return 0;
}

