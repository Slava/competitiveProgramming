// Slava Kim 10b KarKTL
//German, privet
#include <cstdio>
#include <cmath>
using namespace std;

#define MAXN 1000001

bool notPrime[MAXN + 1];
int primes[MAXN];

//resheto blabalalalal
int sieve(int n) {
	int primesCount = 0;
	int sqrt_n = (int)sqrt((double)n);
	for (int i = 2; i <= n; ++i) {
		if (!notPrime[i]) {
			primes[primesCount++] = i;
			if (i <= sqrt_n)
				for (int j = i * i; j <= n; j += i)
					notPrime[j] = true;


		}
	}
	return primesCount;
}

int main ()
{
    freopen ("prime.in", "r", stdin);
    freopen ("prime.out", "w", stdout);

    int n, i = 0, m;
    scanf ("%d%d", &m, &n);
    int count = sieve(n);


    while (primes[i] < m && i < count)i++;

    /*debug
    for (int i = 0; i < count; i++)
        printf("%d ", primes[i]);
    printf("%d %d", count, i);
    *///enddebug

    if((count-i) == 0)
        printf("Absent");

    for( ; i < count; i++)
        printf("%d\n", primes[i]);

    return 0;
}
