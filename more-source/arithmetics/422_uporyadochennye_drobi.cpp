// Kim Vyacheslav KarKTL
#include <cstdio>

using namespace std;

#define prev ((i-1)%2)
#define cur (i%2)

class item
{
    public:
        int a,b;
}f[2][100000];

int n, l[2];

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    scanf ("%d", &n);

    f[0][0].a = 0;
    f[0][0].b = f[0][1].a = f[0][1].b = 1;
    l[0] = 2;

    for (int i = 1; i < n; i++)
    {
        l[cur] = 1;
        f[cur][0].a = f[prev][0].a;
        f[cur][0].b = f[prev][0].b;
        for (int j = 1; j < l[prev]; j++)
        {
            if (f[prev][j - 1].a + f[prev][j].a < f[prev][j - 1].b + f[prev][j].b
                && f[prev][j - 1].b + f[prev][j].b <= n)
            {
                f[cur][l[cur]].a = f[prev][j - 1].a + f[prev][j].a;
                f[cur][l[cur]++].b = f[prev][j - 1].b + f[prev][j].b;
            }
            f[cur][l[cur]].a = f[prev][j].a;
            f[cur][l[cur]++].b = f[prev][j].b;
        }
    }
    for (int i = 1; i < l[(n - 1) % 2] - 1; i++)
        printf ("%d/%d\n", f[(n - 1) % 2][i]);

    return 0;
}
