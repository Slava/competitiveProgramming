#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int n = 300000;
int main() {
    freopen("sum.in", "w", stdout);
    printf("%d\n", n);
    printf("+ 1\n");
    for (int i = 1; i < n; i++) {
        if (rand()&1)
            printf("+ %d\n", rand());
        else {
            printf("? ");
            int x = rand(), y = rand();
            if (y < x)
                swap(x, y);
            printf("%d %d\n", x, y);
        }
    }
    return 0;
}

