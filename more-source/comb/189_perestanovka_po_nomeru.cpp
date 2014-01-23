#include <iostream>

using namespace std;

long i, n, k, a[20];
bool u[20];

int f(int n)
{
    int r = 1;
    for(int i = 2; i <= n; i++)
        r *= i;
    return r;
}

int main ()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%ld%ld", &n, &k);

    k--;

    for(i = 0; i < n; i++)
    {
        a[i] = 1;

        while(u[a[i]])a[i]++;

        for(int j = 0; j < k/f(n-1-i); j++)
        {
            a[i]++;
            while(u[a[i]])a[i]++;
        }

        k %= f(n-1-i);
        u[a[i]] = 1;
    }

    for(i = 0; i < n; i++)
        printf("%ld ", a[i]);

    return 0;
}
