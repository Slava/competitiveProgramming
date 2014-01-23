#include <cstdio>
#include <cstdlib>

char a[2000][5] = {"1000"}, t;
int n;

int main ()
{
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf ("%s", a[i]);
	a[++n][0] = '2';
	a[n][1] = '0';
	a[n][2] = a[n][3] = '1';
	for (int i = 1; i < n; i++)
	{
		if (atoi(a[i - 1]) < atoi(a[i]))
			for (int j = 0; j < 4; j++)
			{
				t = a[i][j];
				a[i][j] = '0' + !j;
				if (atoi(a[i - 1]) <= atoi(a[i]))
					break;
				a[i][j] = t;
			}
		else for (int j = 3; j >= 0; j--)
		{
			t = a[i][j];
			a[i][j] = a[i - 1][j];
			if (atoi(a[i - 1]) <= atoi(a[i]))
				break;
			if (a[i][j] != '9')
				a[i][j]++;
			if (atoi(a[i - 1]) <= atoi(a[i]))
				break;
			a[i][j] = t;
		}
		if (atoi(a[i - 1]) > atoi(a[i]))
		{
			puts("No solution");
			return 0;
		}
	}
	for (int i = 1; i < n; i++)
		printf("%s\n", a[i]);
    return 0;
}

