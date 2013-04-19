#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 110;
double A[N][N], *a[N];
int n, i, j, k;
int main() {
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j <= n; j++)
			scanf("%lf", &A[i][j]);
		a[i] = A[i];
	}
	for (i = 0; i < n; i++) {
		k = i;
		for (j = i + 1; j < n; j++)
			if (abs(a[j][i]) > abs(a[k][i]))
				k = j;
		swap(a[i], a[k]);
		for (j = i + 1; j <= n; j++)
			a[i][j] /= a[i][i];
		for (j = 0; j < n; j++)
			if (j != i)
				for (k = i + 1; k <= n; k++)
					a[j][k] -= a[i][k] * a[j][i];
	}
	for (i = 0; i < n; i++)
		printf("%.10lf ", a[i][n]);
	return 0;
}
