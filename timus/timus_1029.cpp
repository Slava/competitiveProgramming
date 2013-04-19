#include <cstdio>

#define min(a,b) (a<b?a:b)
long long n, m, a[200][700], nn,
	b[200][700], ans[140000], mn;
int main () {
	scanf("%lld%lld", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%lld", &a[i][j]), b[i][j] = (1 << 30);
	for (int i = 0; i < m; i++)
		b[0][i] = a[0][i];
	for (int i = 1; i < n; i++){
		b[i][0] = a[i][0] + b[i - 1][0];
		for (int j = 1; j < m; j++)
			b[i][j] = min(b[i - 1][j], b[i][j - 1]) + a[i][j];
		for (int j = m - 2; j >= 0; j--)
			b[i][j] = min(b[i][j], b[i][j + 1] + a[i][j]);
	}
	for (int i = 0; i < m; i++)
		if (b[n - 1][i] < b[n - 1][mn])
			mn = i;
	for (int i = n - 1; i; ){
		ans[nn++] = mn;
		if (mn && b[i][mn] - a[i][mn] == b[i][mn - 1])
			mn--;
		else if (mn != m - 1 && b[i][mn] - a[i][mn] == b[i][mn + 1])
			mn++;
		else if (b[i][mn] - a[i][mn] == b[i - 1][mn])i--;
	}
	printf("%lld ", mn + 1);
	for (int i = nn - 1; i >= 0; i--)
		printf("%lld ", ans[i] + 1);
	return 0;
}

