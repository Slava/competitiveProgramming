#include <cstdio>
#include <vector>
using namespace std;

int n,m , a[30][30];
vector <int> A;
int u[1000];
int main ()
{
    freopen ("chocolate.in","r",stdin);
    freopen ("chocolate.out","w",stdout);

    scanf("%d%d", &n,&m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf ("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < n-1; i++)
    {
        bool T = 0;
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == a[i+1][j])
            {
                T = 1;break;
            }
        }
        if (!T)
        {
            puts("Yes");exit(0);
        }
    }
    for (int j = 0; j < m-1; j++)
    {
        bool T = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i][j] == a[i][j+1])
            {
                T = 1; break;
            }
        }
        if (!T)
        {
            puts("Yes");exit(0);
        }
    }

    puts("No");


    return 0;
}

