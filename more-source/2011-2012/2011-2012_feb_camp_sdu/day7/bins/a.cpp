#include <cstdio>

const int N = 20010;
const int M = 1010;

int pref[N][M];
int n, m, a[N], ans;

int main() {
	freopen("bins.in", "r", stdin);
	freopen("bins.out", "w", stdout);

	scanf("%d%d", &m, &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a+i);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if (i) pref[i][j] += pref[i-1][j];
			if (a[i] == j)
				pref[i][j]++;
		}

	for (int i = 1; i <= n/2; i++) {
		int r = i+i, cnt = 0;
		for (int j = 1; j <= m; j++) {
			cnt -= pref[r][j] - pref[i][j];
			if (cnt < 0) cnt = 0;
			cnt += pref[i][j];
		}
		if (!cnt && i > ans)
			ans = i;
	}

	printf("%d\n", ans);	

	return 0;
}

