#include <cstdio>
#include <cstdlib>


int main ()
{
	srand(47876567);
	int n = 50000;printf("%d\n", n);
	for (int i = 0; i < n; i++)
	{
		int x, y = 0;
		x = rand() % 1000000;
		while (y < x)
			y = rand() % 1000000;
		printf("%d %d\n", x, y);
	}
}

