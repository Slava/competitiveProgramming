#include <cstdio>
#include <vector>

using namespace std;

#define pb push_back

int all[1 << 11], N, n, k;
bool d[1 << 11][1 << 11];
short kc[1 << 11];
long long a[11][1 << 11][100];
long long ans;

bool bit(int m, int i)
{
	if (i < 0 || i >= n)
		return 0;
	return m & (1 << i);
}

void go (int p, int l, int K)
{
	if (K > k)
		return ;
	if (l == n)
	{
		all[N] = p;
		kc[N++] = K;
		return ;
	}
	go(p, l + 1, K);
	if(!bit(p, l - 1))
		go(p | (1 << l), l + 1, K + 1);
}

bool can (int m1, int m2)
{
	m1 = all[m1];
	m2 = all[m2];
	for (int i = 0; i < n; i++)
		if (bit(m1, i))
			if (bit(m2, i - 1) | bit(m2, i) | bit(m2, i + 1))
				return 0;
	return 1;
}

int main ()
{
	scanf ("%d%d", &n, &k);
	go(0,0,0);
	for (int i = 0; i < N; i++)
		for (int j = i; j < N; j++)
			d[j][i] = d[i][j] = can(i, j);
	for (int i = 0; i < N; i++)
		a[0][i][kc[i]] = 1;
	for (int i = 0; i < n - 1; i++)
		for (int m1 = 0; m1 < N; m1++)
			for (int m2 = 0; m2 < N; m2++)
				for (int p = 0; p <= k; p++)
					if (d[m1][m2] && p + kc[m2] <= k)
						a[i + 1][m2][p + kc[m2]] += a[i][m1][p];
	for (int i = 0; i < N; i++)
			ans += a[n - 1][i][k];
	printf("%I64d\n", ans);
	return 0;
}

