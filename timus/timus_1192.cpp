#include <cmath>
#include <cstdio>
#include <cstdlib>

double b, v, a, m, pi = 3.1415926535;
int main() {
	scanf("%lf%lf%lf", &v, &a, &m);	
	printf("%.2lf", sin(a*pi/90.0)/(m-1.0)/10.0*v*v*m);
	return 0;
}
