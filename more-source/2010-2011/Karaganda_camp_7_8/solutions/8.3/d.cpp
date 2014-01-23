#include <cstdio>

using namespace std;

int a[]={2,4,5}, n, s[19];

void gen (int x)
{
    if (x == n)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += (s[i] == 2);
        if (sum > 2)return;
        for (int i = 0; i < n; i++)
            printf ("%d ", s[i]);
        printf("\n");
        return;
    }
    for (int i = 0; i < 3; i++)
    {
        s[x] = a[i];
        gen(x+1);
    }
}

int main ()
{
    scanf ("%d", &n);
    gen (0);

    return 0;
}

