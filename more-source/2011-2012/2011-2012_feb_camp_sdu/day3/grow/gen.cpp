#include <cstdio>
#include <cstdlib>

int n, m, a[200];
int x;

int main(int ar, char **argc) {
	int seed;
	sscanf(argc[1], "%d", &seed);
	srand(seed);
	n = 100; m = 100;
	for (int i = 0; i < n; i++) {
		if (rand()%100 > 80)
			x++;
		a[i] = x;
	}

	printf("%d %d\n", n, m);
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	puts("");
	for (int i = 0; i < m / 2; i++) {
		int x = rand() % n + 1, y = rand() %  ::x;
		printf("F %d %d\n", x, y);
		x = rand() % ::x; y = x + rand() % (::x - x);
		printf("C %d %d\n", x, y);
	}

	return 0;
}

