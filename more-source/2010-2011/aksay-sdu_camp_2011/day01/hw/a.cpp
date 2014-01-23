#include <cstdio>
#include <iostream>

using namespace std;

long long a[4000][4000], n, m, h, w, M = 99999999999999999LL;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    scanf ("%lld%lld%lld%lld", &n, &m, &h, &w);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            a[i][j] +=
                a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
            if (i >= h && j >= w)
                M = min (M,
                    (a[i][j] - a[i - h][j] - a[i][j - w] + a[i - h][j - w]) / h / w);
        }
    cout << M;

    return 0;
}
