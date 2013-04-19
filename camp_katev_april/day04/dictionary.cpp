#include <cstdio>

int n, k, a[15];
bool u[15];
int f[15];
int main ()
{
	freopen("dictionary.in", "r", stdin);
	freopen("dictionary.out", "w", stdout);
	
	f[0] = 1;
	for (int i = 1; i < 13; i++)
		f[i] = f[i - 1] * i;
	scanf ("%d%d", &n, &k);
	k--;
	for (int i = 0; i < n; i++)
	{
		int c = 0;
		for (int j = 0; j < n; j++)
			if (u[j])
				continue;
			else 
			{
				c += f[n - i - 1];
				if (c > k)
				{
					a[i] = j;
					u[j] = 1;
					k -= c - f[n - i - 1];
					break;
				}
			}
	}
	for (int i = 0; i < n; i++)
		printf("%c", a[i] + 'a');
	return 0;
}

