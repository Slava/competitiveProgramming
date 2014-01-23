#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N = 120;
int n, k, a[N], d[N][N];
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	scanf("%d", &k);

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= k; j++)
			d[i][j] = 1 << 30;

	d[0][0] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++) {
			int cnt = 0;
			for (int l = i + 1; l <= n; l++) {
				cnt += a[l];
				d[l][j + 1] = min(d[l][j + 1], max(cnt, d[i][j]));
			}
		}

	printf("%d", d[n][k]);

	return 0;
}
