#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

#define sz(x) ((int)x.size())

int nextInt();
long long nextInt64();

char str[500], *s;
int a[100][100], u[100][100], d[] = {1,0,-1,0,0,1,0,-1};
int qx[10000], qy[10000], h, t, L, R, U, D;
int main() {
#ifndef ONLINE_JUDGE
//    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n = nextInt(); L = U = 1000;
    a[50][50] = n; u[50][50] = 1;
    qx[t] = qy[t++] = 50;
    while (h < t) {
        int x = qx[h], y = qy[h++];
        L = min(L, y); R = max(R, y);
        U = min(U, x); D = max(D, x);
        if (!a[x][y])continue;
        for (int i = 0; i < 8; i += 2) {
            int dx = x + d[i], dy = y + d[i + 1];
            if (!u[dx][dy]) {
                u[dx][dy] = 1;
                a[dx][dy] = a[x][y] - 1;
                qx[t] = dx; qy[t++] = dy;
            }
        }
    }

    for (int i = U; i <= D; i++) {
        str[0] = 0;
        s = str;
        for (int j = L; j <= R; j++)
            if (u[i][j])
                s += sprintf(s, "%d ", a[i][j]);
            else s += sprintf(s, "  ");
        int len = strlen(str);
        while(str[len - 1] == ' ')
            len--;
        str[len] = 0;
        printf("%s\n", str);
    }

    return 0;
}

int nextInt() {
    int x;
    scanf("%d", &x);
    return x;
}

long long nextInt64() {
    long long x;
    scanf("%I64d", &x);
    return x;
}




// lang: GNU C++
// memory: 1500 KB
// author: imslavko
// submit_date: Oct 7, 2011 7:13:21 PM
// contest: 118
// link: /contest/118/submission/742041
// time: 10 ms
// verdict: Accepted
// problem: 118B - Present from Lena
// ID: 742041
// downloaded by very stupid script
