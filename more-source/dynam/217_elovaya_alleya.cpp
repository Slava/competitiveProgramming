// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    int n, m, w[109], e[109], a[109], d[109][109], mini, i, j, k, l, ans = 1;

    cin >> m;
    for (i = 0; i < m; i++)
        cin >> w[i] >> e[i];

    cin >> n;
    for (i = 0; i < n; i++)
        cin >> a[i];

    memset (d, -1, sizeof(d));

    for (mini = 0, i = 1; i < m; i++)
        if (e[mini] > e[i])
            mini = i;
    for (i = 0; i < n; i++)
        d[i][1] = mini;

    for (i = 1; i < n; i++)                     // for each place
        for (j = 1; j <= i + 1; j++)    // for each possible number to place
            for (k = 0; k < i; k++)             // check out every place befoure
                if (d[k][j - 1] != -1 && e[d[k][j - 1]] + a[k] <= a[i]) // if shadow of tree standing there is acceptable
                    for (l = 0; l < m; l++)     // what tree would we put to new place?
                        if (a[i] - w[l] >= a[k] && (d[i][j] == -1 || e[l] < e[d[i][j]]))
                        {
                            d[i][j] = l;
                            ans = max (ans, j);
                        }
    cout << ans;

    return 0;
}

