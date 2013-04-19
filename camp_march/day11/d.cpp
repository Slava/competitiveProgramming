#include <cstdio>
#include <cstring>

#ifdef WIN32
#define i64 "%I64d"
#else 
#define i64 "%lld"
#endif

char s[300];
int a[300], b[300], n, m, p, c[300], N;
void get(int a[300], int &n)
{
	scanf ("%s", s);
	n = strlen(s);
	for (int i = 0; i < n; i++)
		a[i] = s[n - i - 1] - '0';
	for (int i = n - 1;--a[i] < 0; i--)
		a[i] += 10;
	while (n && !a[n - 1])
		n--;
}

void div2()
{
	int carry;
	for (int i = N - 1; i >= 0; i--)
	{
		c[i] += carry * 10;
		carry = c[i] & 1;
		c[i] >>= 1;
		if (!c[i] && i == N - 1)
			N--;
	}
}

int main ()
{
	freopen ("D.in", "r", stdin);
	freopen ("D.out", "w", stdout);
	get(a, n); get(b, m);
	scanf ("%d", &p);
	int i, j, carry = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (i + j + 1 > N)
				N = i + j + 1;
			c[i + j] += a[i] * b[j] + carry;
			carry = c[i + j] / 10;
			c[i + j] %= 10;
		}
		for (;carry; j++)
		{
			if (i + j + 1 > N)
				N = i + j + 1;
			c[i + j] += carry;
			carry = c[i + j] / 10;
			c[i + j] %= 10;
		}
	}
	long long R = 1, A = 2;
	while (N)
	{
		if (c[0] & 1)
			R = (R * A) % p;
		A = (A * A) % p;
		div2();
	}

	printf( i64 , R);
	return 0;
}


