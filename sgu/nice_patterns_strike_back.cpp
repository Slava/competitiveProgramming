// 197
#include <cstdio>
#include <cstring>
#define bit(x,y) ((x >> y)&1)

int m, p, N;
short n[200];
struct matrix
{
	int a[1 << 5][1 << 5];
	matrix(int K = 1)
	{
		if (K)
		for (int i = 0; i < (1 << 5); i++)
			for (int j = 0; j < (1 << 5); j++)
				a[i][j] = (i == j);
		else memset(a, 0, sizeof a);
	}
	void operator *= (matrix &b)
	{
		matrix c(0);
		for (int i = 0; i < (1 << m); i++)
			for (int j = 0; j < (1 << m); j++)
				for (int k = 0; k < (1 << m); k++)
					c.a[i][j] = (c.a[i][j] + a[i][k] * b.a[k][j]) % p ;
		*this = c;
	}
}D(0);

void div2()
{
	int c = 0;
	for (int i = N - 1; i >= 0; i--)
	{
		n[i] += c * 10;
		c = n[i] & 1;
		n[i] >>= 1;
		if (!n[i] && i == N - 1)
			N--;
	}
}

matrix binpow(matrix a)
{
	matrix res;
	while (N)
	{
		if (n[0] & 1)
			res *= a;
		a *= a;
		div2();
	}
	return res;
}

bool can (int m1, int m2)
{
	for (int i = 1; i < m; i++)
		if ((bit(m1,i)&bit(m2,i)&bit(m1,i-1)&bit(m2,i-1))||
		   !(bit(m1,i)|bit(m2,i)|bit(m1,i-1)|bit(m2,i-1)))
		   	return 0;
	return 1;
}

int main ()
{
	char s[200];
	scanf("%s", s);
    N = strlen(s);
	for (int i = 0; i < N; i++)
		n[i] = s[N - i - 1] - '0';
	for (int i = 0; --n[i] < 0; i++)
		n[i] += 10;
	if (!n[N - 1]) N--;
	scanf("%d%d", &m, &p);
	for (int i = 0; i < (1 << m); i++)
		for (int j = i; j < (1 << m); j++)
			D.a[i][j] = D.a[j][i] = can(i,j);
	matrix ans = binpow(D);
	long long res = 0;
	for (int i = 0; i < (1 << m); i++)
		for (int j = 0; j < (1 << m); j++)
			if (ans.a[i][j])
				res = (res + ans.a[i][j]) % p;
	printf("%lld", res );
	return 0;
}

