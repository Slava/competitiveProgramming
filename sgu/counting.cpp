// 117
#include <cstdio>

const int N = 10100;
bool p[N];
int n, m, k, pr[N], prc, K[N], A[N], ans;
int main ()
{
	for (int i = 2; i < N; i++) if (!p[i])
	{
		pr[prc++] = i;
		for (int j = i + i; j < N; j += i)
			p[j] = 1;
	}
	scanf ("%d%d%d", &n, &m, &k);
	for (int i = 0; i < prc; i++)
		while (k % pr[i] == 0)
			k /= pr[i], K[i]++;
	for (int j = 0; j < n; j++)
	{
		int x;
		scanf ("%d", &x);
		bool bad = 0;
		for (int i = 0; i < prc && !bad; i++)
		{
			if (!K[i])
				continue;
			while (x % pr[i] == 0)
				x /= pr[i], A[i]++;
			A[i] *= m;
			if (A[i] < K[i])
				bad = 1;
			A[i] = 0;
		}
		ans += !bad;
	}
	printf("%d\n", ans);
	return 0;
}

