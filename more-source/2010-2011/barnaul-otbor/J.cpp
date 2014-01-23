#include <cstdio>
#include <iostream>
using namespace std;
int n, i, j, a[200009], b[200009], p;
void qs(int l, int r) {
    int i = l, j = r, x = a[(l + r) / 2];
    do {
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        if ( i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    } while (i <= j);
    if (l < j) qs(l, j);
    if (i < r) qs(i ,r);
}
int main ()
{
    freopen("jolly.in ","r",stdin);
    freopen("jolly.out ","w",stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        if (i  > 0) a[i] = abs(b[i] - b[i - 1]);
    }
    n--;
    qs(1, n);
    for (i = 1; i <= n; i++)
        if (a[i] != i)
            p = 1;
    if (p == 1) printf("Not jolly");
    else printf("Jolly");
}
