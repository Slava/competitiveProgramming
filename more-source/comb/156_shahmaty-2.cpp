#include <iostream>

using namespace std;

long n, k, s;

long p (long x, long k, long f)
{
    if(!f)return 0;
    if(k == 1)return (n-x+1)*f;
    long r = 0;
    for(x++ ; x <= n; x++)
        r += p(x, k-1, f-1);
    return r*f;
}

int main ()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    scanf("%ld%ld", &n, &k);
    s = p(1, k, n);
    printf("%ld", s);

    return 0;
}
