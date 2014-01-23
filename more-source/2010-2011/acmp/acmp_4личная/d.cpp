#include <cstdio>

using namespace std;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    long long ans;
    long long n, m;

    scanf("%lld%lld", &n, &m);
    printf("%lld", (n+m-1)*2);

    return 0;
}
