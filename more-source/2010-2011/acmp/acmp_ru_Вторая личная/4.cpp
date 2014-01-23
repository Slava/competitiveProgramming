// Kim Vyacheslav KarKTL
#include <cstdio>

using namespace std;
long  i, j, k, l, a[9999], b[9999], r;
int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    scanf("%ld%ld", &l, &r);
    b[1] = 1;
    a[1] = a[2] = 1;
    for (i = 1; i <= l / 2; i++) {
        for (j = i * 2, k = 1; j <= i * 3; j++, k++)
            b[j] = (b[j] + a[k]) % r;
        for (j = i + 3; j > 0; j--)
            a[j] += a[j - 1];
    }
    printf("%ld ", b[l]);
    return 0;
}
