#include <cstdio>
#include <cstdlib>

int c[100100], a[100100], n, v;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
		c[(i - a[i] + 1 + n) % n]++;
	}
	for (int i = 0; i < n; i++)
		if (c[i] > c[v])
			v = i;
	printf("%d\n", v + 1);
	return 0;
}
