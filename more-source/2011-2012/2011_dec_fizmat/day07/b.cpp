#include <cstdio>
#include <cstdlib>

const int N = 101010;
int n;
double x[N], v[N];

double f(double t) {
	double min = 1e18, max = 0;

	for (int i = 0; i < n; i++) {
		double d = x[i] + v[i] * t;
		if (d < min)
			min = d;
		if (d > max)
			max = d;
	}

	return max - min;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lf%lf", x + i, v + i);
	
	int cnt = 100000000 / n;;
	if (cnt < 500)
		cnt = 500;
	double l = 0, r = 1e20;
	while (r - l >= 1e-12 && cnt > 0) {
		cnt--;
		double ll = l + (r - l) / 3.,
			   rr = r - (r - l) / 3.;
		if (f(ll) > f(rr))
			l = ll;			
		else r = rr;
//		printf("ll %lf %lf\nrr %lf %lf\n\n", ll, f(ll), rr, f(rr));
	}

	if (f(l) > f(0))
		l = 0;

	printf("%.12lf %.12lf\n", l, f(l));

	return 0;
}
