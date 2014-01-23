#include <iostream>
using namespace std;

bool u[20];
int n, a[20], i, s[2], m = 1000000;

bool f(int x)
{
     if(x == n)
     {
        s[0] = s[1] = 0;
        for(i = 0; i < n; i++)
            s[u[i]] += a[i];
        m = min(m, abs(s[0]-s[1]) );
        return 0;
     }
     f(x+1);
     u[x] = 1;
     f(x+1);
     u[x] = 0;
}

int main ()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d",&a[i]);

    f(0);

    printf("%d", m);

    return 0;
}
