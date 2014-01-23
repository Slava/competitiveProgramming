// Kim Vyacheslav KarKTL
#include <cstdio>
#include <iostream>
using namespace std;

void d2(int k) {
    int i;
    for (i = 1; i <= n; i++) {
        if (a[k][i] > 0) {
            if (o[i] < 2) {
                c[i] = 1;
                o[i] = 2;
                d2(i);
            }
        }
    }
}
void d(int k, int l) {
    int i, j;
    b[l++] = k;
    u[k] = 1;
    for (i = 1; i <= n; i++) {
        if (a[k][i] > 0) {
            if (u[i] == 0)
                d(i);
            else {
                for (j = 0; j < l; j++)
                    o[b[j]] = 2;
                for (j = 0; j < l; j++)
                    d2(b[j]);
            }
        }
    }
}
int main ()
{
    freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
    cin >> n >> m;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            a[i][j] = -1;
    for (i = 0; i < m; i++) {
        cin >> x >> y >> z;
        a[x][y] = max(a[x][y], z);
    }
    d(1, 0);
    return 0;
}
