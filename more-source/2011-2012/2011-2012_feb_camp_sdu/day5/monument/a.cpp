#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>

const int N = 160;
int a[N][N][N], n, m, k, ans, b[N][N], A[N][N][N];
int st[N], sz, L[N], R[N];
char s[N];

void squareDp(int n, int m, int a[N][N]) {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (!a[i][j]) continue;
			else a[i][j] = std::min(std::min(a[i-1][j], a[i][j-1]), a[i-1][j-1]) + 1;
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	std::swap(n,m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			scanf("%s", s+1);
			for (int l = 1; l <= k; l++)
				A[i][j][l] = s[l]=='N';
		}

	for (int l = 1; l <= k; l++) {
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				b[i][j] = A[i][j][l];
		squareDp(n,m,b);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				a[i][j][l] = b[i][j];
	}

	for (int x = 1; x <= n; x++)
		for (int y = 1; y <= m; y++) {
			sz = 0;

			// right border
			for (int i = 1; i <= k; i++) {
				while (sz > 0 && a[x][y][st[sz-1]] > a[x][y][i]) {
					R[st[--sz]] = i-1;
				}
				st[sz++] = i;
			}

			while (sz > 0)
				R[st[--sz]] = k;

			// left border
			for (int i = k; i > 0; i--) {
				while (sz > 0 && a[x][y][st[sz-1]]> a[x][y][i]) {
					L[st[--sz]] = i+1;
				}
				st[sz++] = i;
			}
			
			while (sz > 0)
				L[st[--sz]] = 1;


			for (int i = 1; i <= k; i++)
				ans = std::max(ans, a[x][y][i] * (R[i]-L[i]+1) * 4);
		}

	for (int l = 1; l <= m; l++) {
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= k; j++)
				b[i][j] = A[i][l][j];
		squareDp(n,k,b);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= k; j++)
				a[i][l][j] = b[i][j];
	}

	for (int x = 1; x <= n; x++)
		for (int y = 1; y <= k; y++) {
			sz = 0;

			// right border
			for (int i = 1; i <= m; i++) {
				while (sz > 0 && a[x][st[sz-1]][y] > a[x][i][y]) {
					R[st[--sz]] = i-1;
				}
				st[sz++] = i;
			}

			while (sz > 0)
				R[st[--sz]] = m;

			// left border
			for (int i = m; i > 0; i--) {
				while (sz > 0 && a[x][st[sz-1]][y] > a[x][i][y]) {
					L[st[--sz]] = i+1;
				}
				st[sz++] = i;
			}
			
			while (sz > 0)
				L[st[--sz]] = 1;


			for (int i = 1; i <= m; i++)
				ans = std::max(ans, a[x][i][y] * (R[i]-L[i]+1) * 4);
		}

	for (int l = 1; l <= n; l++) {
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= k; j++)
				b[i][j] = A[l][i][j];
		squareDp(m,k,b);
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= k; j++)
				a[l][i][j] = b[i][j];
	}

	for (int x = 1; x <= m; x++)
		for (int y = 1; y <= k; y++) {
			sz = 0;

			// right border
			for (int i = 1; i <= n; i++) {
				while (sz > 0 && a[st[sz-1]][x][y] > a[i][x][y]) {
					R[st[--sz]] = i-1;
				}
				st[sz++] = i;
			}

			while (sz > 0)
				R[st[--sz]] = n;

			// left border
			for (int i = n; i > 0; i--) {
				while (sz > 0 && a[st[sz-1]][x][y] > a[i][x][y]) {
					L[st[--sz]] = i+1;
				}
				st[sz++] = i;
			}
			
			while (sz > 0)
				L[st[--sz]] = 1;


			for (int i = 1; i <= n; i++)
				ans = std::max(ans, a[i][x][y] * (R[i]-L[i]+1) * 4);
		}
	printf("%d\n", ans);

	return 0;
}

