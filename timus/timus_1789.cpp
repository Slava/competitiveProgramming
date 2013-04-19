#include <cstdio>
#include <cstdlib>

int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", n * 2 - 1);
	for (int i = 1; i <= n; i++)
		printf("%d ", i);
	for (int i = n; i > 1; i--)
		printf("%d ", i);
	return 0;
}
