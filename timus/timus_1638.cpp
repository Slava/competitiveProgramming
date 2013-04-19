#include <cstdio>

int main() {
	int a, b, l, p;
	scanf("%d%d%d%d", &l, &p, &a, &b);
	if (a == b)
		printf("%d\n", l);
	if (a < b)
		printf("%d\n", p * 2 + (b - a - 1) * (l + 2 * p));
	if (a > b)
		printf("%d\n", (a - b + 1) * (l + 2 * p) - 2 * p);
	return 0;
}
