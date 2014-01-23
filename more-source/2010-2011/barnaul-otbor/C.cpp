#include <cstdio>
#include <iostream>
using namespace std;
int n, p, e[99], r[9999], q[9999], v;
string s[99], c[99];
void d(int l, int k, int a, int b) {
    if (l < n) {
        v = l / 3;
        for (int i = 0; i < n; i++) {
            if (e[i] == 0) {
                if (l % 3 == 0) {
                    c[l] = s[i];
                    e[i] = 1;
                    if (v * 3 <= l + 9) d(l + 1, 0, 0, 0);
                    c[l] = "";
                    e[i] = 0;
                }
                if (l % 3 == 1) {
                    int x = 0, y = 0, z = 0;
                    if (c[l - 1][0] == s[i][0]) x = 1;
                    if (c[l - 1][1] == s[i][1]) y = 1;
                    z = c[l - 1][0] - s[i][0];
                    if (x + y + abs(z) > 0) {
                        c[l] = s[i];
                        e[i] = 1;
                        q[l] = i;
                        if (v * 3 <= l) d(l + 1, z, x, y);
                        c[l] = "";
                        e[i] = 0;
                    }
                }
                if (l % 3 == 2) {
                    if ((abs(k) == 1 &&
                       ((k > 0 && (c[l - 1][0] - 1 == s[i][0] || c[l - 2][0] + 1 == s[i][0]))
                    ||  (k < 0 && (c[l - 1][0] + 1 == s[i][0] || c[l - 2][0] - 1 == s[i][0]))))
                    || (a == 1 && s[i][0] == c[l - 1][0]) || (b == 1 && s[i][1] == c[l - 1][1])) {
                        c[l] = s[i];
                        e[i] = 1;
                        if (v * 3 <= l) d(l + 1, 0, 0, 0);
                        c[l] = "";
                        e[i] = 0;
                    }
                }
            }
        }
    }
    else p = 1;
}
int main ()
{
    freopen("coins.in ","r",stdin);
    freopen("coins.out","w",stdout);
    for (n = 0; cin >> s[n]; n++);
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (s[i][0] > s[j][0])
                swap(s[i], s[j]);
    d(0, 0, 0, 0);
    if (p == 1) printf("yes");
    else printf("no");
}
