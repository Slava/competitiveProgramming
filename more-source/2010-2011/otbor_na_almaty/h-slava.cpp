#include <cstdio>

using namespace std;

int a, b, c, A[1000], B;

int main ()
{
    freopen ("santa.in","r",stdin);
    freopen ("santa.out","w",stdout);
    scanf ("%d%d%d",&a,&b,&c);
    for (int i = 0; i < b; i++)
    {
        scanf("%d",&B);
        A[B] = 1;
    }
    for (int i = 0; i < c; i++)
    {
        scanf("%d",&B);
        A[B] = 1;
    }
    printf ("%d\n", a-b-c);
    for (int i = 1; i <= a; i++)
        (!A[i])?printf ("%d ", i):0;
    return 0;
}

