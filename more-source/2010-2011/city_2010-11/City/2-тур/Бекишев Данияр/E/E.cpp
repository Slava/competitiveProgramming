#include <iostream>
#include <cstdio>
using namespace std;
long long t[1001][1001] , n , m , a[1001][1001] , i , j;
char p;
main()
{
    freopen("A.in" , "r" , stdin);
    freopen("A.out" , "w" , stdout);
    cin >> n >> m;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            cin >> p;
            a[i][j] = p - 48;
        }
    }
    for(i = n; i > 0; i--)
    {
        for(j = 1; j <= m; j++)
        {
            if(a[i][j] == 1)
            {
                t[i][j] = t[i + 1][j] + t[i][j - 1];
            }
            t[n][1] = 1;
        }
    }
    if(t[1][m] > 0)
    {
        cout << t[1][m];
    }
    else
    {
        cout << "impossible";
    }
}
