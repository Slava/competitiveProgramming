// Kim Vyacheslav KarKTL
#include <cstdio>

using namespace std;

int a[30];

int check (int f, int s, int n)
{
    a[0] = f;
    a[1] = s;
    for (int i = 2; i < n; i++)
        a[i] = a[i - 1] + a[i - 2];
    return a[n - 1];
}

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    int x, y;
    scanf ("%d%d", &x, &y);
    for (int i = 1; i < 1001; i++)
        for (int j = i - 1; j > 0; j--)
            if (check (i,j,x) == y)
            {
                printf ("%d %d", i, j);
                return 0;
            }


    return 0;
}
