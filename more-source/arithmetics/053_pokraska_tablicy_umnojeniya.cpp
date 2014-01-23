// Kim Vyacheslav KarKTL
#include <cstdio>

using namespace std;

int ans[5];

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    int n, m, p;
    scanf ("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            p = 1;
            if (i*j % 2 == 0) p = 2;
            if (i*j % 3 == 0) p = 3;
            if (i*j % 5 == 0) p = 4;
            ans[p]++;
        }
    printf ("RED : %d\nGREEN : %d\nBLUE : %d\nBLACK : %d\n", ans[2], ans[3], ans[4], ans[1]);

    return 0;
}
