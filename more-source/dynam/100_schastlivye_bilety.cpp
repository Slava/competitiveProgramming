#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n, i, j, k, a[500][500][109], l, m, ans[1009];

void sum(int i, int j, int k)
{
    int c = 0;
    for (int x = 0; x < 101; x++)
    {
        a[i][j][x] += a[i - 1][j - k][x] + c;
        c = a[i][j][x] / 10;
        a[i][j][x] %= 10;
    }
}

void d(int z)
{
    int x[1009], c = 0;
    for (int i = 0; i < 1001; i++) x[i] = 0;
    for (int i = 0; i < 101; i++)
    {
        for (int j = 0; j < 101; j++)
        {
            x[i + j] += a[m][z][i] * a[m][z][j] + c;
            c = x[i + j] / 10;
            x[i + j] %= 10;
        }
    }
    for (int i = 0; i < 1000; i++) ans[i] += x[i] + c, c = ans[i] / 10, ans[i] %= 10;
}
void out(int i, int j)
{
    int x;
    for (x = 100; x > 0 && !a[i][j][x]; x--);
    for (; x >= 0; x--) cout << a[i][j][x];
    cout << endl;
}
main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    cin >> n;
    m = n / 2;
    for (i = 0; i <= 9; i++)
        a[1][i][0] = 1;
    for (i = 2; i <= m; i++)
    {
        for (j = 0; j <= i * 9; j++)
        {
            if (!j) a[i][j][0] = 1;
            else
            {
                for (k = 0; k <= 9; k++)
                {
                    if (j - k >= 0)
                    sum(i, j, k);
                }
            }
            //out(i, j);
        }
    }

    for (i = 0; i <= m * 9; i++)
    {
       // out(m, i);
        d(i);
    }
    for (i = 201; i > 0 && !ans[i]; i--);
    for (; i >= 0; i--) cout << ans[i];
}
