#include <cstdio>
#include <cstring>
#include <cstdlib>

int n, m;
char s[600][600];
int main(int argn, char **arg) {
	int seed;
//	n = rand() % 500+1; m = rand() % 500+1;
	n = m = 500;
	if (m%2 != n%2)
		m++;
	sscanf(arg[0], "%d", &seed);
	srand(seed);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
//			s[i][j] = (rand()&1) ? '/' : '\\';
	s[i][j] = '/';
	printf("%d %d\n", n, m);
	for (int i = 0; i < n; i++)
		printf("%s\n", s[i]);
	return 0;
}

