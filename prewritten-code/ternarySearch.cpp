#include <cstdio>
#include <cmath>

typedef double (*function_type)(double);

double alpha, betta, a, b, eps = 1e-8, pi = acos(-1.);

double ternarySearch(double l, double r, function_type f);
double innerFunction(double x) {
	betta = x;
	double h1 = cos(alpha) * a,
		   w1 = sin(alpha) * a,
		   h2 = cos(betta) * b,
		   w2 = sin(betta) * b;
	return h2 * w1 + h1 * w1 / 2 + h2 * w2 / 2;
}

double outerFunction(double x) {
	alpha = x;
	return ternarySearch(0, pi, innerFunction);
}

// searches for point x in [l;r], such that f(x) is maximum
double ternarySearch(double l, double r, function_type f) {
	double ll, rr;
	for (int i = 0; i < 1000 && r - l > eps; i++) {
		ll = l + (r - l) / 3;
		rr = r - (r - l) / 3;

		if (f(ll) < f(rr))
			l = ll;
		else 
			r = rr;
	}

	return f(l);
}

int main() {
	scanf("%lf%lf", &a, &b);
	printf("%.9lf\n", ternarySearch(0, pi, outerFunction));
	return 0;
}
