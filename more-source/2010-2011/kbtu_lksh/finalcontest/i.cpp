#define file "I"
#include <cstdio>
#include <algorithm>
#include <utility>
#include <iostream>
#include <cstdlib>

using namespace std;

#define mp make_pair
#define f first
#define s second
pair<int, pair<int,int> >a[1000010];
int n, m, p[1010], ans;
int get(int x) {
    if (p[x] != x)
        p[x] = get(p[x]);
    return p[x];
}

void unite(int x, int y) {
    if (rand() & 1)
        p[x] = y;
    else p[y] = x;
}

int main() {
    freopen(file ".in", "r", stdin);
    freopen(file ".out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        p[i] = i;
    for (int i = 0; i < m; i++) {
        cin >> a[i].s.f >> a[i].s.s >> a[i].f;
        a[i].f *= -1;
    }
    sort(a, a + m);
    for (int i = 0; i < m; i++) {
        int x = get(a[i].s.f);
        int y = get(a[i].s.s);
        if (x != y) {
            unite(x, y);
            ans += a[i].f;
        }
    }
    cout << -ans;
    return 0;
}
