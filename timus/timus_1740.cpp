#include <cstdio>
#include <cstdlib>

int m, k, h;
int main() {
	scanf("%d%d%d", &m, &k, &h);
	double a = m / k; a *= h;
	double b = a;
	if (m % k != 0)
		a += 0.00001,
		b += h - 0.00001;
	printf("%.5lf %.5lf\n", a, b);
	return 0;
}
