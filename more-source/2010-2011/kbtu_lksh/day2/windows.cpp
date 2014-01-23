#define file "windows"
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <algorithm>

using namespace std;

#define f first
#define s second

typedef pair<int,int> ii;
const int PL = 200010;
const int N = 50100;

struct Seg{
    int x, o, y1, y2;
}seg[N * 2], T;
bool operator < (Seg a, Seg b) {
    if (a.x == b.x)
        return a.o;
    return a.x < b.x;
}

int t[PL * 4 + 4], n, mx, ansx, ansy;
ii s[PL * 4 + 4];

void update(int l, int r, int x, int i = 1, int tl = 0, int tr = PL * 2 - 1) {
    if (l == tl && r == tr)
        t[i] += x;
    else {
        int m = (tl + tr) >> 1;
        t[i + i] += t[i];
        t[i + i + 1] += t[i];
        t[i] = 0;
        if (l > m)
            update(l, r, x, i + i + 1, m + 1, tr);
        else if (r <= m)
            update(l, r, x, i + i, tl, m);
        else update(l, m, x, i + i, tl, m), update(m + 1, r, x, i + i + 1, m + 1, tr);
    }
    if (tl != tr) {
        ii L = s[i + i], R = s[i + i + 1];
        L.f += t[i + i]; R.f += t[i + i + 1];
        s[i] = max(L, R);
    }
    else {
        s[i] = ii(0, l);
    }
}

ii getmax(int l, int r, int i = 1, int tl = 0, int tr = PL * 2 - 1) {
    if (l == tr && r == tr)
        return s[i];
    int m = (tl + tr) >> 1;
    if (l > m)
        return getmax(l, r, i + i + 1, m + 1, tr);
    if (r <= m)
        return getmax(l, r, i + i, tl, m);
    ii L = s[i + i], R = s[i + i + 1];
    L.f += t[i]; R.f += t[i];
    return max(L, R);
}

int main() {
    freopen(file ".in", "r", stdin);
    freopen(file ".out", "w", stdout);

    scanf("%d", &n);
    int x1, x2, y1, y2;
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        if (y1 > y2)
            swap(y1, y2);
        if (x1 > x2)
            swap(x1, x2);
        y1 += PL; y2 += PL;
        T.o = 1; T.x = x1; T.y1 = y1; T.y2 = y2;
        seg[i * 2] = T; T.x = x2; T.o = 0; seg[i * 2 + 1] = T;
    }
    sort(seg, seg + n + n);
    for (int i = 0; i < n + n; i++) {
        if (seg[i].o)
            update(seg[i].y1, seg[i].y2, 1);
        else update(seg[i].y1, seg[i].y2, -1);
        ii TT = getmax(0, PL * 2 - 1);
        if (TT.f > mx) {
            mx = TT.f;
            ansx = seg[i].x;
            ansy = TT.s;
        }
    }
    printf("%d\n%d %d\n", mx, ansx, ansy - PL);
    return 0;
}

