#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;
int n, m, a, i, j;
bool u[999], f[999];
int main ()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    scanf("%d%d", &n, &m);
    for (j = 1; j <= m; j++) {
        scanf("%d", &a);
        f[a] = true;
    }
    for (i = 2; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            scanf("%d", &a);
            u[a] = true;
        }
        for (j = 0; j <= 250; j++) {
            f[j] = f[j] & u[j];
            u[j] = false;
        }
    }
    for (i = 0; i <= 250; i++)
        if (f[i] == true)
            break;
    printf("%d", i);
}

