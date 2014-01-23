#define file "H"
#include <cstdio>

int n, m, x, y;
int main() {
    freopen(file ".in", "r", stdin);
    freopen(file ".out", "w", stdout);
    scanf("%d%d%d%d", &x, &n, &y, &m);
    x += y;
    x += m - n;
    x = (x + 24) % 24;
    printf("%d\n", x);
    return 0;
}
