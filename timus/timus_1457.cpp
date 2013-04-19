#include <cstdio>

int s, x, n, i;
int main() {
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &x), s += x;
	printf("%.6lf", s * 1. / n);
	return 0;
}
