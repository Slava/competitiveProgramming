#define file "permutations"
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 10001;
int n, m, a[N], t[N][N];

int main() {
    freopen(file ".in", "r", stdin);
    freopen("tup.out", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
        t[i + 1][a[i]]++;
    }
    for (int i = 0; i < m; i++) {
        int x, y, k, l;
        scanf("%d%d%d%d", &x, &y, &k, &l);
        int s = 0;
        for (int X = x; X <= y; X++)
            for (int Y = k; Y <= l; Y++)
                s += t[X][Y];
        printf("%d\n", s);
    }
    return 0;
}

