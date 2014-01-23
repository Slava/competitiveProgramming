#include <iostream>

using namespace std;

int a[2009], n, i, j, b[2009], f;
bool u[2009];

int main ()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(i = n-1; i >= 0; i--)
    {
        f = n;
        while(u[f])f--;
        for(j = 0; j < a[i] ; j++)
        {
            f--;
            while(u[f])f--;
        }
        b[i] = f;
        u[f] = true;
    }

    for(i = 0; i < n; i++)
        printf("%d ", b[i]);

    return 0;
}
