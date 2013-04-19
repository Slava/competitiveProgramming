#include <cstdio>
#include <cmath>

long double a[1000100];
int n;

int main() {
	for (; scanf("%Lf", a + n) == 1; n++);
	for (; n; n--)
		printf("%.4Lf\n", sqrtl(a[n - 1]));
	return 0;
}

