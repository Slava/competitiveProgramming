#define file "inc"
#include <cstdio>
int n;
int main() {
    freopen(file ".in", "r", stdin);
    freopen(file ".out", "w", stdout);

    scanf("%d", &n);
    printf("1 ");
    for (int i = 2; i < n - 1; i++)
        printf("%d ", n - i);
        printf("%d ", n - 1);

    return 0;
}
