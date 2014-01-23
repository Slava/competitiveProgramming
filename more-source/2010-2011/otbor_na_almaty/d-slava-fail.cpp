#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

bool a[100][100];
int n, m;

int r (int x, int y, int maxr)
{
    int i = 1;
    for (; i < maxr; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            int away = ceil(sqrt(j*j-i*i+.0));
            printf("%d %d %d\n",i,j,away);
            if (!(a[y+j][x+away]&&a[y+j][x-away]&&a[y-j][x+away]&&a[y-j][x-away]))
            return --i;
        }
    }
    return --i;
}

int main ()
{
    freopen ("moon.in", "r", stdin);
    freopen ("moon.out", "w", stdout);

    scanf ("%d%d",&n,&m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            char t;
            scanf("%c", &t);
            a[i][j] = t == '*';
        }
    int m = -1, ansx, ansy;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!a[i][j])continue;
            int T = r(j,i,min(min(i,j),min(m-j,n-i)));
            if (m < T)
            {
                m = T;
                ansx = j;
                ansy = i;
            }
        }
    }
    printf ("%d\n%d %d", m, ansx,ansy);

    return 0;
}
