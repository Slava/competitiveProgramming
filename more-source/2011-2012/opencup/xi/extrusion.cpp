#include <cstdio>
#define abs(x) (x<0?-(x):x)

double x[30], y[30];

double vect(int i, int j) {
	return x[i]*y[j]-x[j]*y[i];
}

double solve() {
	double res = 0, v;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lf%lf", x+i, y+i);
	x[n] = x[0]; y[n] = y[0];
	scanf("%lf", &v);

	for (int i = 0; i < n; i++){
		res += vect(i,i+1);
	}
	res = abs(res) / 2.;
	return v / res;
}

int main() {
#ifndef imslavko
	freopen("extrusion.in", "r", stdin);
	freopen("extrusion.out", "w", stdout);
#endif

	int t;
	scanf("%d", &t);
	while(t--)
		printf("%.2lf\n", solve());
	return 0;
}
