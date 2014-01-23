#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;
int n, a[100];
char s[109][10009];
void d(int k,int j, int l) {
    int i;
    if (k < l) {
        for (i = j; i <= n; i++) {
            a[k] = i;
            d(k + 1, i + 1, l);
        }
    }
    else {
        for (i = 0; i < l; i++)
            printf("%d ", a[i]);
        printf("\n");
    }
}
int main ()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%s", s[i]);
    for (int i = 1; i <= n; i++)
        d(0, 1, i);
}
