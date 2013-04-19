#include <cstdio>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;
const int N = 100010;

ull p[N], pr[2][N], f[N], P = 1717;
int n, fn, ai;
char s[N], t[N];

inline ull hash(int J, int i, int j)
{
	ull h = pr[J][j];
	if (i) h -= pr[J][i - 1];
	h *= p[n - i - 1];
	return h;
}

bool can (int m)
{
	fn = 0;
	for (int i = 0; i + m <= n; i++)
		f[fn++] = hash(1, i, i + m - 1);
	sort(f, f + fn);
	for (int i = 0; i + m <= n; i++)
		if (binary_search(f, f + fn, hash(0, i, i + m - 1)))
		{
			ai = i;
			return 1;
		}
	return 0;
}

int main ()
{
	scanf ("%d\n%s\n%s", &n, s, t);
	p[n - 1] = 1;
	for (int i = n - 2; i >= 0; i--)
		p[i] = p[i + 1] * P;
	for (int i = 0; i < n; i++)
	{
		pr[0][i] = (s[i] - 'A' + 1) * p[i];
		pr[1][i] = (t[i] - 'A' + 1) * p[i];
		if (i)
			pr[0][i] += pr[0][i - 1],
			pr[1][i] += pr[1][i - 1];
	}
	int l, r, m;
	l = 1; r = n;
	while (l <= r)
	{
		m = (l + r) / 2;
		if (can(m))
			l = m + 1;
		else r = m - 1;
	}
	for (int i = ai; i < ai + l - 1; i++)
		printf("%c", s[i]);
	return 0;
}


