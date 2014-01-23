#define file "G"
#include <cstdio>
#define FOR(i,n) for(int i = 0; i < n; i++)
#define min(a,b) (a<b?a:b)
const int N = 50;
int n, m;
int a[N][N][N][N], d[N][N][N][N], b[N][N][N][N], c[N][N][N][N], A[N][N][N][N];
int main() {
    freopen(file ".in", "r", stdin);
    freopen(file ".out", "w", stdout);

    scanf("%d%d", &n, &m);
    FOR(i,n)FOR(j,n)FOR(k,n)FOR(l,n)
        scanf("%d", &a[i][j][k][l]);
//    printf("\n\n\n\n\n");
    FOR(i,n)FOR(j,n)FOR(k,n)
        for (int l = 0; l < n - m + 1; l++) {
            d[i][j][k][l] = (1 << 30);
            for (int z = 0; z < m; z++)
                d[i][j][k][l] = min(d[i][j][k][l], a[i][j][k][l + z]);
        }
    FOR(i,n)FOR(j,n)
        for (int k = 0; k < n - m + 1; k++)
            for (int l = 0; l < n - m + 1; l++) {
                b[i][j][k][l] = (1<<30);
                for (int z = 0; z < m; z++)
                    b[i][j][k][l] = min(b[i][j][k][l], d[i][j][k + z][l]);
            }
    FOR(i,n)
        for (int j = 0; j < n - m + 1; j++)
            for (int k = 0; k < n - m + 1; k++)
                for (int l = 0; l < n - m + 1; l++) {
                    c[i][j][k][l] = (1<<30);
                    for (int z = 0; z < m; z++)
                        c[i][j][k][l] = min(c[i][j][k][l], b[i][j + z][k][l]);
                }
    for (int i = 0; i < n - m + 1; i++)
        for (int j = 0; j < n - m + 1; j++)
            for (int k = 0; k < n - m + 1; k++)
                for (int l = 0; l < n - m + 1; l++) {
                    A[i][j][k][l] = (1<<30);
                    for (int z = 0; z < m; z++)
                        A[i][j][k][l] = min(A[i][j][k][l], c[i + z][j][k][l]);
                    printf("%d ", A[i][j][k][l]);
                }
    return 0;
}
