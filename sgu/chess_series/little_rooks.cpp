#include <iostream>
#include <cstdio>

using namespace std;

#define long long long

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
								          
     scanf("%lld%lld", &n, &k);
     s = p(1, k, n);
	 s += !k;
     printf("%lld", s);

      return 0;
}
