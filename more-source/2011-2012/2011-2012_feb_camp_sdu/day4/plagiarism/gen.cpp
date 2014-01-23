#include <cstdio>
#include <cstdlib>

int main(int x, char **arg) {
	int seed;
	sscanf(arg[1], "%d", &seed);
	srand(seed);
	int n = 100; 
	printf("%d\n", n);
	for (int i = 0; i < n; i++)
		printf("%d ", rand() % 100000000);
}

