#include <cstdio>

using namespace std;

int primes[10000], leastp[10000], prcount = 1;

void sieve (int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (leastp[i] == 0)
        {
            primes[prcount++] = i;
            leastp[i] = prcount;
        }
        for (int j = 1; j <= leastp[i]; j++)
        {
            if (primes[j] * i > n)
                break;
            leastp[primes[j] * i] = j;
        }
    }
}

int main ()
{
    int n;
    scanf ("%d", &n);
    sieve(n);
    for (int i = 1; i < prcount; i++)
        printf ("%d ", primes[i]);

    return 0;
}

