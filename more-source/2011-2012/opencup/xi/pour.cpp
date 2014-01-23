#include <cstdio>
#include <cstdlib>

int main() {
#ifndef imslavko
	freopen("pour.in", "r", stdin);
	freopen("pour.out", "w", stdout);
#endif

	int a, b, n, t, c;
	scanf("%d%d%d", &n, &a, &b);
	c = b / a;
	t = (n+c-1)/c;

	printf("%d\n", (n-t)&1?1:2);

	return 0;
}
