#define file "A"
#include <cstdio>

int n;
int main() {
    freopen(file ".in", "r", stdin);
    freopen(file ".out", "w", stdout);
    scanf("%d", &n);
    if (n > 10000)
        printf("%d\n", n - 10000);
    if (n%10000 != 1)
        printf("%d\n", n - 1);
    if (n%10000 != 0)
        printf("%d\n", n + 1);
    if (n < 100000000 - 10000 + 1)
        printf("%d\n", n + 10000);
    return 0;
}
