#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 2100;

int a[N], n, dp[N][N], bx, by;
int i, j, k, D, st[N], b[N], p[N];
int main() {
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", a + i), b[i] = a[i];
	sort(a, a + n);
	for (i = 0; i < n; i++) {
		dp[i][i] = 1;
		for (j = i + 1; j < n; j++)
			if (a[i] < a[j]) {
				dp[i][j] = 2;
				bx = i; by = j;
			}
		p[lower_bound(a, a + n, b[i]) - a] = i + 1;
	}
	for (i = 1; i < n; i++)
		for (j = 0; j < i; j++) {
			D = a[i] - a[j];
			if (!D || !binary_search(a, a + n, a[j] - D))
				continue;
			k = lower_bound(a, a + n, a[j] - D) - a;
			dp[j][i] = dp[k][j] + 1;
			if (dp[bx][by] < dp[j][i])
				bx = j, by = i;
		}
	D = a[by] - a[bx]; k = dp[bx][by]; j = a[by] - D * (k - 1);
	printf("%d\n", k);
	for (i = 0; i < k; i++, j += D)
		printf("%d ", p[lower_bound(a, a + n, j) - a]);
	return 0;
}

