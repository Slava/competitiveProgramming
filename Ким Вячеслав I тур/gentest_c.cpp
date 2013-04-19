#include <cstdio>
#include <cstdlib>

int a[10000000], n, pl, ms;
int main ()
{
	n = 200000;
	printf("%d\n", n);
	for (int i = 0; i < n; i++)
	{
		char cmd = rand() & 1 ? '+' : '-';
		unsigned int x = rand() * rand() * rand();
		x %= 10000000;
		if (cmd == '-' && !a[x])
		{i--; continue;}
		printf("%c %d\n", cmd, x);
	}
	return 0;
}

