#include <cstdio>

int main () {
    freopen("bfsrev.in", "w", stdout);
    printf("100000 1 99999\n");
    for (int i = 2; i <= 100000; i++)
        printf("%d 1\n", i);
}
