// Kim Vyacheslav KarKTL
#include <cstdio>
#include <vector>

using namespace std;

bool prime[1000000];
vector <int> primes, superprimes;

void resheto ()
{
    primes.push_back(1);
    prime[0] = prime[1] = 1;
    for (int i = 2; i < 1000000; i++)
        if (!prime[i]){
            for (int j = i + i; j < 1000000; j += i)
                prime[j] = 1;
            primes.push_back(i);
        }
}

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    resheto();
    int n;
    scanf ("%d", &n);
    for (int i = 0; i < primes.size(); i++)
        if (!prime[i])
            superprimes.push_back(primes[i]);
    printf("%d ", superprimes[n - 1]);

    return 0;
}
