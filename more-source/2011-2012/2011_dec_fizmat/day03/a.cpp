#include <cstdio>
#include <cstdlib>

int n, k;
const int mod = 1000000007;

int a[52][52], res[52][52], c[52][52];

int Mod(long long a) {
	if (a > mod)
		a %= mod;
	return (int)a;
}

void mult(int a[52][52], int b[52][52]) {
	for (int i = 0; i <= k; i++)
		for (int j = 0; j <= k; j++)
			c[i][j] = 0;
	
	for (int i = 0; i <= k; i++)
		for (int j = 0; j <= k; j++)
			for (int l = 0; l <= k; l++)
				c[i][j] = Mod(c[i][j] + Mod(a[i][l] * 1LL * b[l][j]));
	for (int i = 0; i <= k; i++)
		for (int j = 0; j <= k; j++)
			a[i][j] = c[i][j];
}

int main() {
	freopen("sum.in", "r", stdin);
	freopen("sum.out", "w", stdout);

	scanf("%d%d", &n, &k);
	for (int i = 0; i <= k; i++) {
		a[0][i] = 1;
		for (int j = 1; j <= k; j++)
			a[j][i] = (a[j][i - 1] + a[j - 1][i - 1]) % mod;
	}

	a[k][k + 1] = a[k + 1][k + 1] = 1;
	k++;

	for (int i = 0; i <= k; i++)
		res[i][i] = 1;
	n++;

	while (n > 0) {
		if (n & 1)
			mult(res, a);
		mult(a, a);
		n >>= 1;
	}

	printf("%d\n", Mod(res[0][k]));
	return 0;
}
