#include <cstdio>
#include <cstring>
#define bit(x,y) (((x)>>(y))&1)

const int SZ = 31, ZS = 200;
int m, p, N;
short n[ZS];
struct matrix {
	int a[SZ][SZ];
	matrix(int K = 1) {
		if (K)
		for (int i = 0; i < SZ; i++)
			for (int j = 0; j < SZ; j++)
				a[i][j] = (i == j);
		else memset(a, 0, sizeof a);
	}
	void operator *= (matrix &b) {
		matrix c(0);
		for (int i = 0; i < m; i++)
			for (int j = 0; j < m; j++)
				for (int k = 0; k < m; k++)
					c.a[i][j] = (c.a[i][j] + a[i][k] * b.a[k][j]) % p;
		*this = c;
	}
}D(0);

void div2() {
	int c = 0;
	for (int i = N - 1; i >= 0; i--) {
		n[i] += c * 10;
		c = n[i] & 1;
		n[i] >>= 1;
		if (!n[i] && i == N - 1)
			N--;
	}
}

matrix binpow(matrix a) {
	matrix res;
	while (N) {
		if (n[0] & 1)
			res *= a;
		a *= a;
		div2();
	}
	return res;
}

int main () {
	char s[ZS];
	int a[SZ + 2], x[SZ + 2];
	scanf("%d%d", &m, &p);
	for (int i = 0; i < m; i++)
		scanf("%d", a + i);
	scanf("%d", x + m);
	for (int i = 0; i < m; i++)
		scanf("%d", x + i);

	// N start
	scanf("%s", s);
    N = strlen(s);
	for (int i = 0; i < N; i++)
		n[i] = s[N - i - 1] - '0';
	for (int i = 0; --n[i] < 0; i++)
		n[i] += 10;
	if (!n[N - 1]) N--;
	// N finish
	for (int i = 0; i < m - 1; i++)
		D.a[i][i + 1] = 1;
	D.a[m][m] = 1;
	for (int i = m - 1; i >= 0; i--)
		D.a[m - 1][i] = a[m - i - 1];
	D.a[m - 1][m] = 1;
	m++;

	matrix ans = binpow(D);
	long long res = 0;
	for (int i = 0; i < m; i++)
		res = (res + x[i] * ans.a[0][i]) % p;
	printf("%lld", res );
	return 0;
}

