#include <cstdio>
#include <cstdlib>

int n, m, a[50];
int main() {
	scanf("%d", &n); if (n == 1) {printf("0");return 0;}
	for (; n != 1; a[m++] = n)
		n = (n + 1) >> 1;
	printf("%d\n", m);
	for (int i = 0; i < m; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}
