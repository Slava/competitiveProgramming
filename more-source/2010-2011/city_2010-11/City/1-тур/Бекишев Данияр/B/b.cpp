#include <iostream>
#include <cstdio>
using namespace std;
int n , m , a[999] , i , j , b , used[999];
int main()
{
    freopen("A.in" , "r" , stdin);
    freopen("A.out" , "w" , stdout);
    cin >> n >> m;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j < 251; j++)
        {
            used[j] = 0;
        }
        for(j = 1; j <= m; j++)
        {
            cin >> b;
            if(used[b] == 0)
            {
                used[b] = 1;
                a[b]++;
            }
        }
    }
    for(i = 1; i < 251; i++)
    {
        if(a[i] == n)
        {
            cout << i;
            break;
        }
    }
}
