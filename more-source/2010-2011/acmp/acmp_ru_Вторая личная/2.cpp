// Kim Vyacheslav KarKTL
#include <cstdio>

using namespace std;

long a[12], n, f[15], ans1;
long b[11], v[12];
bool V = 0;

void F ()
{
    f[1] = f[0] = 1;
    for (int i = 2; i <= 14; i++)
        f[i] = f[i-1] * i;
}

long p (int j, int x, long sum, long mult)
{
    if (j==n)
    {
        long curans = f[n];
        if (mult == sum)
        {
            if (!V)
            {
                for (int i = 0; i < n; i++)
                    v[i] = a[i];
                V = 1;
            }
            for (int i = 0; i < 10; i++){
                b[i] = 0;
                for (int k = 0; k < n; k++)
                    b[i] += (a[k] == i);
                curans /= f[b[i]];
            }
            ans1+=curans;
            return 1;
        }
        else return 0;
    }
    if (mult > n*9)return 0;
    long res = 0;
    for (int i = x; i < 10; i++)
    {
        a[j] = i;
        res+=p(j+1,i, sum + i, mult * i);
    }
    return res;
}

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    scanf ("%ld", &n);
    if (n == 1){printf("10 0");return 0;}
    long ans = 0;
    F();
    ans = p(0, 1, 0, 1);
    printf ("%ld ", ans1);
    for (int i = 0; i< n; i++)
        printf ("%ld",v[i]);

    return 0;
}
