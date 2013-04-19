#include <cstdio>
int a, b;
int main() {
	scanf("%d%d", &a, &b);
	if (a > 0 && b > 0 && ((a + b) % 2))
		printf("%d %d\n", b, a);
	else printf("%d %d\n", a, b);
	return 0;
}
