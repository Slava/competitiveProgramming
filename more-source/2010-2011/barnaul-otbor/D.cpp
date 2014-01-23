#include <cstdio>
#include <iostream>
using namespace std;
int n, x[99], y[99], p, c[99];
void d(int a, int b, int j) {
   // cout << j << ' ' ;
    if (j < n) {
        for (int i = 0; i < n; i++) {
            if (c[i] == 0) {
                if (x[i] == a) {
                    c[i] = 1;
                    d(y[i], b, j + 1);
                    c[i] = 0;
                }
                if (x[i] == b) {
                    c[i] = 1;
                    d(y[i], a, j + 1);
                    c[i] = 0;
                }
                if (y[i] == a) {
                    c[i] = 1;
                    d(x[i], b, j + 1);
                    c[i] = 0;
                }
                if (y[i] == b) {
                    c[i] = 1;
                    d(x[i], a, j + 1);
                    c[i] = 0;
                }
            }
        }
    }
    else p = 1;
}
int main ()
{
    freopen("domino.in ","r",stdin);
    freopen("domino.out","w",stdout);
    for (n = 0; cin >> x[n] >> y[n]; n++);
    for (int i = 0; i < n; i++) {
        c[i] = 1;
        d(x[i], y[i], 1);
        c[i] = 0;
    }
    if (p == 1) printf("yes");
    else printf("no");
}

